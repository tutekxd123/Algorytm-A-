#include "testsUnit.hpp"

bool testsUnit::testAstarSingleGrid()
{
	Graph graphtest{};
	Graph morecomplex{};

	AstarGrid astar{};
	//Pierwsze co to trzeba wczytanie jsona zrobic "Glaze" i napisaæ struktury danych w sumie moge skopiwaæ z poprzedniego projektu
	auto ec = glz::read_file_json(graphtest, "./tests.json", std::string{});
	if (ec) {
		std::cout << "ERROR JSON LOAD: " << glz::format_error(ec) << '\n';
		std::cout << "FAILED TEST A* SINGLE GRID DUE TO JSON LOAD ERROR\n";
		return false;
	}
	//Pierwszy test na specialnej siatce z tests.json
	//Test A* na jednej siatce bez kolizji powinien zwrocic droge o dlugosci 19 (0+9)+(0+9)=18 krokow + 1 Startowy
	Point Start = graphtest.Grids[0].getPoint(0, 0);
	Point Target = graphtest.Grids[0].getPoint(9, 9);
	//Pierwsze co piszemy A* na jednej siatce
	//Z Racji ze pracujemy nie na wskaznikach a na kopiach trzeba uwzglednic to przy tworzeniu A*
	auto test1 = astar.GetWay(graphtest.Grids[0], Start, Target);
	if(test1.size() != 19)
	{
		std::cout << "TEST A* SINGLE GRID FAILED! Expected path length 19, got " << test1.size() << "\n";
		return false;
	}
	else {
		std::cout << "Test A* Single Grid Passed! nr.1 zero obstacles \n";
	}
	Start = graphtest.Grids[1].getPoint(0, 0);
	Target = graphtest.Grids[1].getPoint(10,10);
	auto test2 = astar.GetWay(graphtest.Grids[1], Start, Target);
	//Expected path length is 23 because of obstacles
	if (test2.size() != 25)
	{
		std::cout << "TEST A* SINGLE GRID FAILED! Expected path length 25, got " << test2.size() << "\n";
		return false;
	}
	else {
		std::cout << "Test A* Single Grid Passed! nr.2 with obstacles \n";
	}
	Start = graphtest.Grids[1].getPoint(0, 0);
	Target = graphtest.Grids[1].getPoint(0,15);
	auto test3 = astar.GetWay(graphtest.Grids[1], Start, Target);
	//Expected no path
	if (test3.size() != 0) {
		std::cout << "TEST A* SINGLE GRID FAILED! Expected no path, got path length " << test3.size() << "\n";
		return false;
	}
	else {
		std::cout << "Test A* Single Grid Passed! nr.3 no possible path \n";
	}
	
	auto ec2 = glz::read_file_json(morecomplex,"./testsmorecomplex.json", std::string{});
	return true;
}

void testsUnit::testBenchmark()
{
	Graph benchmark{};
	auto ec3 = glz::read_file_json(benchmark, "./benchmarktest.json", std::string{});

	auto obj = AstarPlusPlus();
	obj.getWay(benchmark, 8, Point(0, 0), 1);
}


void testsUnit::testBenchmarkMultiple() {
	for (int maps = 10; maps < 150; maps+=5) {
		for (int edgesmax = 4; edgesmax < 7; edgesmax++) {
			for (int sizex = 16; sizex < 32; sizex += 16) {
				//kwadratowe mapy
				Graph benchmark = MakeGraph(maps, edgesmax,sizex, sizex, sizex, sizex, 0);
				size_t sizeofEdges=0;
				for (auto& grid : benchmark.Grids) {
					sizeofEdges += grid.Edges.size();
				}
				int badmap = MakeBadData(benchmark);
				auto obj = AstarPlusPlus();
				obj.getWay(benchmark, badmap, Point(0, 0), badmap==0?1:0);
				std::string formatedstring = std::format("Maps: {}\nSize Map: {}\nEdges: {}\nLengthOperations: {}", maps, sizex * sizex, sizeofEdges,obj.lengthoperations);
				std::cout << formatedstring << std::endl;
			}
		}
	}
	return;
}