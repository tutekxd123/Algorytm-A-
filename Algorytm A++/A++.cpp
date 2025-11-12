#include "A++.hpp"

std::vector<Point> AstarPlusPlus::getWay(const Graph& graph, int GrupaWezlowCel, const Point& StartPoint, int GrupaWezlowStart)
{
	//Zmiana podejscia robimy Graph konwersje na NodeAstarPlusPlus zeby latwiej zarz¹dzac w reconstruct Path
	if (graph.Grids.size() <= GrupaWezlowStart || graph.Grids.size() <= GrupaWezlowCel)
	{
		throw std::invalid_argument("Grupa Wezlow nie istnieje w grafie");
	}
	//Okay Create Vector?
	std::vector<AstarPlusPlusNode> allNodes;
	std::set<AstarPlusPlusNode*, NodePTRComparator>Openset; //Hasher lub comparator! jako kolejka priorytetowa
	std::unordered_set<AstarPlusPlusNode*, NodeHasherPTR> ClosedSet;
	allNodes.reserve(10000);
	for (const auto& grid : graph.Grids) {
		auto node = AstarPlusPlusNode(&grid);
		if (grid.id == GrupaWezlowStart) {
			node.point = StartPoint;
			node.gCost = 0;
			allNodes.emplace_back(node);
			Openset.insert(&allNodes.back());
		}
		else {
			allNodes.emplace_back(&grid);
		}
	}
	while (!Openset.empty()) {
		AstarPlusPlusNode* current = *Openset.begin();
		ClosedSet.insert(current);
		Openset.erase(current);
		if (current->grid->id == GrupaWezlowCel) {
			return ReconstructPath(graph, current);
		}
		std::vector<std::tuple<AstarPlusPlusNode*, size_t, Point>> neighbours = getNeighbors(allNodes, current, graph);
		for (auto& [neigh,dystans,newPoint] : neighbours) {
			//para wskazniku i dystansu!
			if (!Openset.contains(neigh) && !ClosedSet.contains(neigh)) {
				{
					neigh->gCost = current->gCost + dystans;
					neigh->parent = current;
					neigh->point = newPoint;
					Openset.insert(neigh);
					continue;
				}
				//Jezeli juz mial w openset to moze jest to lepsze
				if (Openset.contains(neigh)) {
					int tempgscore = dystans + current->gCost;
					if (neigh->gCost > tempgscore) {
						neigh->gCost = tempgscore;
						neigh->point = newPoint;
						neigh->parent = current;
					}
				}

			}

		}

	};
	return std::vector<Point>();
};


//std::vector<AstarPlusPlusNode> getNeighbors(const std::vector<AstarPlusPlusNode>&AllNodes,const AstarPlusPlusNode* currentNode, const Graph& graph);
std::vector<std::tuple<AstarPlusPlusNode*, size_t, Point>> AstarPlusPlus::getNeighbors(std::vector<AstarPlusPlusNode>& AllNodes, const AstarPlusPlusNode* currentNode, const Graph& graph)
{
	std::vector<std::tuple<AstarPlusPlusNode*,size_t,Point>> result;
	std::vector<Edge> edges = currentNode->grid->Edges;
	Point Start = currentNode->point;
	for (const auto& edge : edges) {
		Point Target = edge.Grid1Point;
		size_t realdistance = AstarGrid::GetWay(*currentNode->grid, Start, Target).size(); //z dystansem cos trzeba zrobic?
		if(realdistance == 0) //W tym kodzie gscore jezeli ==0 to znaczy ze nie ma drogi nawet jednokratkowej(wlacznie z Startem), wiec nie trzeba sprawdzac czy wezel jest startowym
		{
			continue;
		}
		//mamy dystans mamy ID mapy Trzeba z ALlNodes wyciagnac te ID i dodac do wektora wskaznik wskazujacy z allNodes
		//Aczkolwiek jezeli id mamy ponumerowane od 0 w allnodes i sa po kolei to znamy indeks tego prawda?, zalozmy ze tak jest ze index==map.id
		result.emplace_back(&AllNodes[edge.idMapConnect],realdistance,edge.Grid2Point);

	}
	return result;
}


std::vector<Point> AstarPlusPlus::ReconstructPath(const Graph graph, AstarPlusPlusNode* currentNode) //Kopia CurrentNode celowa
{

	std::vector<Point>Wynik;
	int lastconnected = 0;
	while (currentNode->parent != nullptr) {
		//musimy przeczytac z edge! znowu
		Point targetpoint = currentNode->grid->getEdge(currentNode->parent->grid->id).Grid1Point;
		std::cout << currentNode->grid->id<<std::endl;
		auto droga = AstarGrid::GetWay(*currentNode->grid, currentNode->point, targetpoint);
		for (auto& node : droga) {
			Wynik.emplace_back(node);
		}
		lastconnected = currentNode->grid->id;
		currentNode = currentNode->parent;
	}
	//Add last road 
	Point targetpoint = currentNode->grid->getEdge(lastconnected).Grid1Point;
	auto droga = AstarGrid::GetWay(*currentNode->grid, currentNode->point,targetpoint);

	for (auto& node : droga) {
		Wynik.emplace_back(node);
	}
	std::reverse(Wynik.begin(), Wynik.end());
	return Wynik;
}
