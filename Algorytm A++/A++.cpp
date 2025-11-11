#include "A++.hpp"

std::vector<Point> AstarPlusPlus::getWay(const Graph& graph, int GrupaWezlowCel, const Point& StartPoint, int GrupaWezlowStart)
{
//Zmiana podejscia robimy Graph konwersje na NodeAstarPlusPlus zeby latwiej zarz¹dzac w reconstruct Path
	if(graph.Grids.size() <= GrupaWezlowStart || graph.Grids.size() <= GrupaWezlowCel)
	{
		throw std::invalid_argument("Grupa Wezlow nie istnieje w grafie");
	}
	//Okay Create Vector?
	std::vector<AstarPlusPlusNode> allNodes;
	allNodes.reserve(10000);

	//Po rozmiarze mozna
	const Grid& startGrid = graph.Grids[GrupaWezlowStart];
	std::vector<AstarPlusPlusNode>OpenSet;
	std::unordered_set<AstarPlusPlusNode, NodeHasher> ClosedSet;
	std::unordered_set<AstarPlusPlusNode, NodeHasher> OpenSetLookup; //Set only to optimalize find 
	auto startpoint = AstarPlusPlusNode(&startGrid, StartPoint, 0, nullptr);
	OpenSet.emplace_back(startpoint);
	OpenSetLookup.insert(startpoint);
	while (!OpenSet.empty()) {
		AstarPlusPlusNode current = getMinimumNode(OpenSet); //trzeba kopie robic z powodu dynamiki
		ClosedSet.insert(current); //O(1)
		if (current.grid->id == GrupaWezlowCel) {
			std::cout << "Found a path to target grid id: " << GrupaWezlowCel << "\n";
			return ReconstructPath(graph, current);
		}
		//Get Neighbors
		std::vector<AstarPlusPlusNode> neighbors = getNeighbors(&current,graph);
		//Remove current from OpenSet
		OpenSet.erase(std::remove_if(OpenSet.begin(), OpenSet.end(),
			[&current](const AstarPlusPlusNode& node) {
				return node.grid->id == current.grid->id && node.point.x == current.point.x && node.point.y == current.point.y;
			}), OpenSet.end()); //O(N)! Lambda przesuwanie elementow na koniec (remove_if) a potem erase zmiana size vectora
		OpenSetLookup.erase(current);

		for (const auto& neigh : neighbors) {
			//Find in OpenSet maybe use set
			if (!OpenSetLookup.contains(neigh) && !ClosedSet.contains(neigh)) {
				OpenSet.emplace_back(neigh);
				OpenSetLookup.insert(neigh);
				continue;
			}
			if (OpenSetLookup.contains(neigh)) {
				//Dobra ale i tak musimy odstac iterator z Vectora celem update w razie co 
				auto itVec = std::find_if(OpenSet.begin(), OpenSet.end(),[&](const AstarPlusPlusNode& node) { return node == neigh; });
				if (itVec == OpenSet.end()) {
					throw std::runtime_error("W OpenSetLookup jest punkt a w OpenSet go nie ma bug?\n");
				}
				if (itVec->gCost > neigh.gCost) {
					//Aktualizacja w wektorze
					itVec->gCost = neigh.gCost;
					itVec->parentGrid = neigh.parentGrid;
					OpenSetLookup.erase(neigh);
					OpenSetLookup.insert(*itVec);
				}


			}
		}

	}

	return std::vector<Point>();

}

AstarPlusPlusNode AstarPlusPlus::getMinimumNode(std::vector<AstarPlusPlusNode>& openSet)
{
	int gscore = openSet[0].gCost;
	AstarPlusPlusNode minimumNode = openSet[0];
	for (auto& node : openSet) {
		if (node.gCost < gscore) {
			gscore = node.gCost;
			minimumNode = node;
		}
	}
	return minimumNode;
}

std::vector<AstarPlusPlusNode> AstarPlusPlus::getNeighbors(const AstarPlusPlusNode* currentNode, const Graph& graph)
{
	std::vector<AstarPlusPlusNode> result;
	std::vector<Edge> edges = currentNode->grid->Edges;
	Point Start = currentNode->point;
	for (const auto& edge : edges) {
		Point Target = edge.Grid1Point;
		size_t realdistance = AstarGrid::GetWay(*currentNode->grid, Start, Target).size();
		if(realdistance == 0) //W tym kodzie gscore jezeli ==0 to znaczy ze nie ma drogi nawet jednokratkowej(wlacznie z Startem), wiec nie trzeba sprawdzac czy wezel jest startowym
		{
			continue;
		}
		result.emplace_back(&graph.Grids[edge.idMapConnect], edge.Grid2Point, currentNode->gCost + realdistance, currentNode->grid); //dynamiczne tworzenie wezlow
	}
	return result;
}

std::vector<Point> AstarPlusPlus::ReconstructPath(const Graph graph, AstarPlusPlusNode currentNode) //Kopia CurrentNode celowa
{

	std::vector<int>Grupywezlow;
	std::vector<Point>Wynik;
	while (currentNode.parentGrid != nullptr) {
		Grupywezlow.emplace_back(currentNode.parentGrid->id);
		currentNode = currentNode.parentGrid;
	}
	return std::vector<Point>();
}
