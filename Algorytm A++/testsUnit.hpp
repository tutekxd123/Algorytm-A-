#pragma once
#include "Graph.hpp"
#include "Astar.hpp"
#include <iostream>
#include "A++.hpp"
#include "GeneratorSubplazczyznDebug.hpp"
struct benchmark {
	int edges;
	size_t lengthoperations;
	int nodes;
	benchmark(int edges,int lengthoperations, int nodes): edges(edges), lengthoperations(lengthoperations), nodes(nodes) {}
};
template<>
struct glz::meta<benchmark> {
	using T = benchmark;
	static constexpr auto value = glz::object(
		"edges", &T::edges,
		"lengthoperations", &T::lengthoperations,
		"nodes", &T::nodes
	);
};
class testsUnit {
public:
	static bool testAstarSingleGrid();
	static void testBenchmark();
	static void testBenchmarkMultiple();
};