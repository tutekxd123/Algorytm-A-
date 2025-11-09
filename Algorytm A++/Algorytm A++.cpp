#include <iostream>
#include "Graph.hpp"
#include "Astar.hpp"
int main()
{
	Graph graphtest{};
	AstarGrid astar{};
	//Pierwsze co to trzeba wczytanie jsona zrobic "Glaze" i napisać struktury danych w sumie moge skopiwać z poprzedniego projektu
	auto ec = glz::read_file_json(graphtest, "./generated_subspaces.json", std::string{});
	if (ec) {
		std::cout<<"ERROR JSON LOAD: " << glz::format_error(ec)<<'\n';
		return 1;
	}
	Point Start = graphtest.Grids[0].getPoint(0, 0);
	Point Target = graphtest.Grids[0].getPoint(9, 9);
	//Pierwsze co piszemy A* na jednej siatce
	//Z Racji ze pracujemy nie na wskaznikach a na kopiach trzeba uwzglednic to przy tworzeniu A*
	auto test = astar.GetWay(graphtest.Grids[0], Start, Target);

    std::cout << "Hello World!\n";
}
