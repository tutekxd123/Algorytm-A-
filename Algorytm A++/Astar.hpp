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
	void operator=(const Point& point) {
		this->node = &point;
		this->gscore = std::numeric_limits<double>::max();
		this->fscore = std::numeric_limits<double>::max();
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
		if (a->fscore == b->fscore) {
			if (a->node->x == b->node->x) {
				return a->node->y < b->node->y;
			}
			return a->node->x < b->node->x;
		}
		return a->fscore < b->fscore;
	}
};
//Comparator musi zapewniac unikalnac wiec jezeli fscore jest te samo to go nie wstawi
//Dodam
class AstarGrid {
public:
	static double getHeuristic(const AstarNode& start, const Point& target);
	static std::vector<Point> reconstructPath(const AstarNode* node);
	static std::vector<AstarNode*> getNeighbours(std::vector<AstarNode>& grid, const AstarNode* pointnode, int maxheight, int maxwidth);
	static AstarNode& getNode(int x, int y, int maxheight, std::vector<AstarNode>& nodes);
	static std::vector<Point> GetWay(const Grid& grid, const Point& start, const Point& target);
};