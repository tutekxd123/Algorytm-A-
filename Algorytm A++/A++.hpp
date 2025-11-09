#pragma once
#include <iostream>
#include "A++.hpp"
#include "Graph.hpp"

class AstarPlusPlus {
	public:
		static std::vector<Point> getWay(const Graph& graph, int GrupaWezlowCel, const Point& StartPoint, int GrupaWezlowStart);
}