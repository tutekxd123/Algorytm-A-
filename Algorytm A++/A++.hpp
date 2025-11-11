#pragma once
#include <iostream>
#include "Graph.hpp"
#include <unordered_set>
#include "Astar.hpp"
struct AstarPlusPlusNode {
	const Grid* grid = nullptr;
	Point point;
	int gCost = std::numeric_limits<int>::max();
	const Grid* parentGrid = nullptr;
	Point pointParent;

	AstarPlusPlusNode(const Grid* grid, const Point& point, int gCost, const Grid* parentGrid)
		: grid(grid), point(point), gCost(gCost), parentGrid(parentGrid) {
	}
	AstarPlusPlusNode(const Grid*, const Point& point): point(point), gCost(std::numeric_limits<int>::max()), parentGrid(nullptr) {
	}
	//	OpenSet.emplace_back(&startGrid, StartPoint, 0, nullptr);
	bool operator==(const AstarPlusPlusNode& point) const {
		return this->grid == point.grid && this->point == point.point;
	}
};
struct NodeHasher {
	size_t operator()(const AstarPlusPlusNode& point) const
	{
		// Combine hashes of x and y using the bitwise XOR
		return (
			(std::hash<int>()(point.grid->id)) ^
			(std::hash<int>()(point.point.x) << 1) ^
			(std::hash<int>()(point.point.y) << 2)
			);
	}
};

class AstarPlusPlus {
public:
	static std::vector<Point> getWay(const Graph& graph, int GrupaWezlowCel, const Point& StartPoint, int GrupaWezlowStart);
	static AstarPlusPlusNode getMinimumNode(std::vector<AstarPlusPlusNode>& openSet);
	static std::vector<AstarPlusPlusNode> getNeighbors(const AstarPlusPlusNode* currentNode, const Graph& graph);
	static std::vector<Point> ReconstructPath(const Graph graph, AstarPlusPlusNode currentNode);
};