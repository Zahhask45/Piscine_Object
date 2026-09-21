/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 16:52:07 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/21 14:41:15 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <png.h>
#include "graph.hpp"

void readSelection(size_t &value)
{
	if (std::cin >> value)
		return ;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	value = 999999;
}

void readFloat(float &value)
{
	if (std::cin >> value)
		return ;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	value = 999999;
}

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int	main()
{
	Graph graph(Vector2(20.0f, 20.0f));

	try{
		graph.loadPoints("points.txt");
		graph.addPoint(Vector2(8.0f, 8.0f));
		graph.display();
		generatePNG(graph, "graph.png");
		std::cout << "Graph saved to graph.png" << std::endl;
	}
	catch (const std::exception& error){
		std::cerr << "Error: " << error.what() << std::endl;
		return (1);
	}
	return (0);
}
