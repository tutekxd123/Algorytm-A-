#include <iostream>
#include "Graph.hpp"
int main()
{
	Graph graphtest{};
	//Pierwsze co to trzeba wczytanie jsona zrobic "Glaze" i napisać struktury danych w sumie moge skopiwać z poprzedniego projektu
	auto ec = glz::read_file_json(graphtest, "./graph.json", std::string{});
	if (ec) {
		std::cout<<"ERROR JSON LOAD: " << glz::format_error(ec)<<'\n';
		return 1;
	}

    std::cout << "Hello World!\n";
}
