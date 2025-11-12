#include <iostream>
#include "Graph.hpp"
#include "Astar.hpp"
#include "testsUnit.hpp"
#include "A++.hpp"
int main()
{
#ifdef _DEBUG
	bool tests = testsUnit::testAstarSingleGrid();
	if (tests) {
		std::cout << "ALL TESTS PASSED!\n";
	}
	else {
		std::cout << "TESTS FAILED!\n";
		return 1;
	}
	testsUnit::testBenchmark();
#endif // DEBUG


	return 0;
}
