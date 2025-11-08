#include "Graph.hpp"
#include <unordered_set>
#include <set>

#pragma once
class AstarNode {
	public:
		const Point* node = nullptr;
		double gscore = std::numeric_limits<double>::max();
		double fscore = std::numeric_limits<double>::max();
		bool operator==(const AstarNode& othernode) {
			return this->node->x == othernode.node->x && this->node->y == othernode.node->y;
		};
		bool operator<(const AstarNode& othernode) {
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

};

class AstarGrid {
	public:
		double getHeuristic(const Point& start, const Point& target) {
			//Manhattan Distance
			return abs(start.x - target.x) + abs(target.y - start.y);
		}
		std::vector<Point> GetWay(const Grid& grid, const Point& start, const Point& target) {
			std::set<AstarNode> Openset;
			AstarNode startnode = AstarNode(start);
			startnode.fscore = 0;
			startnode.gscore = getHeuristic(*startnode.node,target); //calc distance!
			Openset.insert(AstarNode(start));

		}
};