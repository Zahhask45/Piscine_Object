/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   graph.cpp                                                  _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 13:38:33 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/17 16:25:19 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "graph.hpp"

Graph::Graph(const Vector2& size): size(size){}

bool Graph::isInside(const Vector2& point) const{
	return point.getX() >= 0
		&& point.getY() >= 0
		&& point.getX() < size.getX()
		&& point.getY() < size.getY();
}

bool Graph::addPoint(const Vector2& point){
	if (!isInside(point))
		return false; 

	this->points.push_back(point);	
	return true;
}

void Graph::display() const{
	int x;
	int y;

	for (y = static_cast<int>(size.getY()) - 1; y >= 0; --y){
		std::cout << y << " ";
		for (x = 0; x < static_cast<int>(size.getX()); ++x){
			bool found = false;
			std::vector<Vector2>::const_iterator it;

			for (it = points.begin(); it != points.end(); ++it){
				if (static_cast<int>(it->getY()) == y
					&& static_cast<int>(it->getX()) == x){
						found = true;
						break;
					}
			}
			
			if (found)
				std::cout << "X ";
			else
				std::cout << ". ";
		}
		std::cout << std::endl;
	}		
	std::cout << "  ";
	for (x = 0; x < static_cast<int>(size.getX()); ++x)
		std::cout << x << " ";
	std::cout << std::endl;
}
