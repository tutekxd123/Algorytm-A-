#include "Graph.hpp"
#include <unordered_set>
#include <set>

#pragma once
class AstarNode {
	public:
		const Point* node = nullptr;
		double gscore = std::numeric_limits<double>::max();
		double fscore = std::numeric_limits<double>::max();
		AstarNode* parent = nullptr;

		bool operator==(const AstarNode& othernode) const {
			return this->node->x == othernode.node->x && this->node->y == othernode.node->y;
		};
		bool operator<(const AstarNode& othernode) const {
			return this->fscore > othernode.fscore;
		};
		void operator=(const Point& point){
			this->node = &point;
			double gscore = std::numeric_limits<double>::max();
			double fscore = std::numeric_limits<double>::max();
		}
		AstarNode(const Point& point) {
			this->node = &point;
		}
		bool operator==(const Point& point) const {
			return this->node->x == point.x && this->node->y == point.y;
		}

};
struct ComparatorAstarNode {
	bool operator()(AstarNode* a, AstarNode* b) const {
		return a->fscore > b->fscore;
	}
};
class AstarGrid {
	public:
		double getHeuristic(const AstarNode& start, const AstarNode& target) const{
			//Manhattan Distance
			return abs(start.node->x - target.node->x) + abs(target.node->y - start.node->y);
		}
		std::vector<AstarNode*> getNeighbours(std::vector<AstarNode>& grid, const AstarNode* pointnode, int maxheight, int maxwidth) {
			//Mozliwy kierunek w 4 ruchach
			std::vector<AstarNode*> result;
			result.reserve(4);
			const int possibleMoves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
			for (const auto& move : possibleMoves) {
				int dx = pointnode->node->x + move[0];
				int dy = pointnode->node->y + move[1];
				if (dx >= maxwidth || dy >= maxheight || dx<0 || dy<0) {
					continue;
				}
				AstarNode* newpoint = &grid[(dx * maxheight) + dy];
				if (!newpoint->node->collision) {
					result.emplace_back(newpoint);
				}

			}
			return result;
		};

		AstarNode& getNode(int x, int y,int maxheight, std::vector<AstarNode>& nodes)  {
			return nodes[(x * maxheight) + y];
		}
		std::vector<Point> GetWay(const Grid& grid, const Point& start, const Point& target) {
			std::vector<AstarNode> gridNode;
			gridNode.reserve(grid.points.size());
			for (auto& point : grid.points) {
				gridNode.emplace_back(point);
			}
			int maxheight = grid.height;
			int maxwidth = grid.width;
			//Konwersja na AstarNode Kopiowanie elementow domylsnie w A* tego nie ma.
			//Roznica miedzy implementacja a pseudokodem jest to ze operuje na wskaznikach
			std::set<AstarNode*, ComparatorAstarNode> Openset;
			std::unordered_set<AstarNode*> ClosedSet;
			AstarNode* startnode = &getNode(start.x, start.y, maxheight, gridNode);
			startnode->gscore = 0;
			startnode->fscore = getHeuristic(*startnode->node,target); //calc distance!
			Openset.insert(startnode);
			while (!Openset.empty()) {
				AstarNode* current = *Openset.begin();
				Openset.erase(Openset.begin());
				ClosedSet.insert(current);

				if (*current == target) {
					//Found path
					//Reconstruct path
					return std::vector<Point>();
				}
				std::vector<AstarNode*> neighbors = getNeighbours(gridNode, current,maxheight,maxwidth);
				for (auto& neigh : neighbors) {
					if (ClosedSet.contains(neigh)) {
						continue;
					}
					double tempgscore = current->gscore + 1;

					if (Openset.contains(neigh)) {
						if (tempgscore >= neigh->gscore) {
							continue; //Jezeli jest w Openset i ma gorsza, badz rowna gscore to nie aktualizujemy
						}

					}
					neigh->gscore = tempgscore;
					neigh->fscore = neigh->gscore + getHeuristic(*neigh, target);
					neigh->parent = current;
					if (!Openset.contains(neigh)) {
						Openset.insert(neigh);
					}

				}
			}
			return std::vector<Point>();
		}
};