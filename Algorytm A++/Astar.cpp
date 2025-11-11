#include "Astar.hpp"
#pragma once

	double AstarGrid::getHeuristic(const AstarNode& start, const Point& target) {
		//Manhattan Distance
		return abs(start.node->x - target.x) + abs(target.y - start.node->y);
	}
	std::vector<Point> AstarGrid::reconstructPath(const AstarNode* node) {
		std::vector<Point> result;
		while (node->parent != nullptr) {
			result.emplace_back(*node->node);
			node = node->parent;
		}
		result.emplace_back(*node->node);
		std::reverse(result.begin(), result.end());
		return result;
	}
	std::vector<AstarNode*> AstarGrid::getNeighbours(std::vector<AstarNode>& grid, const AstarNode* pointnode, int maxheight, int maxwidth) {
		//Mozliwy kierunek w 4 ruchach
		std::vector<AstarNode*> result;
		result.reserve(4);
		const int possibleMoves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		for (const auto& move : possibleMoves) {
			int dx = pointnode->node->x + move[0];
			int dy = pointnode->node->y + move[1];
			if (dx >= maxwidth || dy >= maxheight || dx < 0 || dy < 0) {
				continue;
			}
			AstarNode* newpoint = &grid[(dx * maxheight) + dy];
			if (!newpoint->node->collision) {
				result.emplace_back(newpoint);
			}

		}
		return result;
	};

	AstarNode& AstarGrid::getNode(int x, int y, int maxheight, std::vector<AstarNode>& nodes) {
		return nodes[(x * maxheight) + y];
	}
	std::vector<Point> AstarGrid::GetWay(const Grid& grid, const Point& start, const Point& target) {
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
		startnode->fscore = getHeuristic(*startnode->node, target); //calc distance!
		Openset.insert(startnode);
		while (!Openset.empty()) {
			AstarNode* current = *Openset.begin();
			Openset.erase(Openset.begin());
			ClosedSet.insert(current);

			if (*current == target) {
				//Found path
				//Reconstruct path
				return reconstructPath(current);
			}
			std::vector<AstarNode*> neighbors = getNeighbours(gridNode, current, maxheight, maxwidth);
			for (auto& neigh : neighbors) {
				if (ClosedSet.contains(neigh)) {
					continue;
				}
				double tempgscore = current->gscore + 1;

				if (Openset.contains(neigh)) {
					if (tempgscore >= neigh->gscore) {
						continue; //Jezeli jest w Openset i ma gorsza, badz rowna gscore to nie aktualizujemy
					}
					Openset.erase(neigh);


				}
				neigh->gscore = tempgscore;
				neigh->fscore = neigh->gscore + getHeuristic(*neigh, target);
				neigh->parent = current;
				Openset.insert(neigh);

				//Okay so 

			}
		}
		return std::vector<Point>();
	}