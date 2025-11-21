#include "Astar.hpp"
#pragma once

	double AstarGrid::getHeuristic(const AstarNode& start, const Point& target) {
		//this->lengthoperations += 5;
		//Manhattan Distance
		this->lengthoperations += 5;
		return abs(start.node->x - target.x) + abs(target.y - start.node->y);
	}
	std::vector<Point> AstarGrid::reconstructPath(const AstarNode* node,int sizegrid) {
		std::vector<Point> result;
		//Maksymalny wymiar plazczzyzny to 100x100 i podziele na dwa w prrzypadku MAKSYMALNEJ drogi(to trzeba by ustalic? ale na logike mniej wiecej
		//moze dynamicznie zamiast pisac 100x100?
		result.reserve(sizegrid / 2);
		this->lengthoperations+=2;
		while (node->parent != nullptr) {
			result.emplace_back(*node->node);
			node = node->parent;
			this->lengthoperations += 3;
		}
		result.emplace_back(*node->node); //O(1)
		this->lengthoperations += Utility::reverse(&result[0], &result[0] + result.size());
		this->lengthoperations += 3; //dodawanie size + return + emplace_back?
		//reverse mozna samemu
		return result;
	}
	std::vector<AstarNode*> AstarGrid::getNeighbours(std::vector<AstarNode>& grid, const AstarNode* pointnode, int maxheight, int maxwidth) {
		//Mozliwy kierunek w 4 ruchach
		std::vector<AstarNode*> result;
		result.reserve(4);
		const int possibleMoves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		this->lengthoperations += 3;
		for (const auto& move : possibleMoves) {
			int dx = pointnode->node->x + move[0];
			int dy = pointnode->node->y + move[1];
			this->lengthoperations += 2;
			if (dx >= maxwidth || dy >= maxheight || dx < 0 || dy < 0) {
				continue;
			}
			this->lengthoperations += 4;
			AstarNode* newpoint = &grid[(dx * maxheight) + dy];
			
			if (newpoint->node->collision==false) {
				this->lengthoperations += 1;
				result.emplace_back(newpoint);
			}
			this->lengthoperations += 2;

		}
		return result;
	};

	AstarNode& AstarGrid::getNode(int x, int y, int maxheight, std::vector<AstarNode>& nodes) {
		this->lengthoperations += 2;
		return nodes[(x * maxheight) + y];
	}
	std::vector<Point> AstarGrid::GetWay(const Grid& grid, const Point& start, const Point& target) {
		this->lengthoperations = 0;
		std::vector<AstarNode> gridNode;
		gridNode.reserve(grid.points.size());
		this->lengthoperations += 2;
		for (auto& point : grid.points) {
			gridNode.emplace_back(point);
			this->lengthoperations += 1;
		}
		int maxheight = grid.height;
		int maxwidth = grid.width;
		//Konwersja na AstarNode Kopiowanie elementow domylsnie w A* tego nie ma.
		//Roznica miedzy implementacja a pseudokodem jest to ze operuje na wskaznikach
		MinHeap<double, AstarNode*, HasherAstarNodePTR> OpenSet;
		std::unordered_set<AstarNode*> ClosedSet;
		AstarNode* startnode = &getNode(start.x, start.y, maxheight, gridNode);
		if (startnode->node->collision) {
			this->lengthoperations +=1;
			return std::vector<Point>();
		}
		startnode->gscore = 0;
		startnode->fscore = getHeuristic(*startnode->node, target); //calc distance!
		OpenSet.insert(0, startnode);
		this->lengthoperations+=9;
		while (!OpenSet.isEmpty()) {
			AstarNode* current;
			OpenSet.getMin(current);
			OpenSet.deleteMin();
			ClosedSet.insert(current);

			if (*current == target) {
				this->lengthoperations += 1;
				//Found path
				//Reconstruct path
				this->lengthoperations += OpenSet.lengthoperations;
				return reconstructPath(current,(grid.height*grid.width));
			}
			std::vector<AstarNode*> neighbors = getNeighbours(gridNode, current, maxheight, maxwidth);
			this->lengthoperations += 1;
			for (auto& neigh : neighbors) {
				if (ClosedSet.contains(neigh)) {
					this->lengthoperations += 1;
					continue;
				}

				double tempgscore = current->gscore + 1;
				this->lengthoperations += 2;
				if (OpenSet.contains(neigh)) {
					if (tempgscore >= neigh->gscore) {
						this->lengthoperations += 1;
						continue; //Jezeli jest w Openset i ma gorsza, badz rowna gscore to nie aktualizujemy
					}
					this->lengthoperations += 1;

				}

				neigh->gscore = tempgscore;
				neigh->fscore = neigh->gscore + getHeuristic(*neigh, target);
				neigh->parent = current;

				if (OpenSet.contains(neigh)) {
					OpenSet.update(neigh->fscore, neigh);

				}
				else {
					OpenSet.insert(neigh->fscore, neigh);
				}
				this->lengthoperations += 6;

			}
		}
		this->lengthoperations += OpenSet.lengthoperations;
		return std::vector<Point>();
	}