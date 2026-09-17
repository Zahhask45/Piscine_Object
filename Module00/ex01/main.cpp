/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 16:52:07 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/17 16:52:23 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */


#include <cstdlib>
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
	size_t option = 1;
	Graph graph(Vector2(11.0f, 11.0f));
	
	graph.display();
	while (option){
		readSelection(option);
		if (option == 1){
			float x = 0;
			float y = 0;

			readFloat(x);
			readFloat(y);
			clearScreen();
			graph.addPoint(Vector2(x, y));
		}
	}

	
// 
// 	graph.addPoint(Vector2(0.0f, 0.0f));
// 	graph.addPoint(Vector2(2.0f, 2.0f));
// 	graph.addPoint(Vector2(4.0f, 2.0f));
// 	graph.addPoint(Vector2(2.0f, 4.0f));
	return (0);
}
