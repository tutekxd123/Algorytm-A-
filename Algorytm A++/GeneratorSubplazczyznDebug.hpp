#pragma once
#include "Graph.hpp"
#include <unordered_set>
struct PairHash {
	std::size_t operator()(const std::pair<int, int>& p) const noexcept {
		return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1); //Hash to pary <int,int> prosty(zeby set mogl wyszukiwac>)
	}
};
int MakeBadData(Graph& graph);
Graph MakeGraph(int sizemap = 10, int maxconnonmaps = 5, int minx = 0, int maxx = 100, int miny = 0, int maxy = 100, int chanceofcoll = 20);