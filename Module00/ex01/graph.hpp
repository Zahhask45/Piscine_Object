/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   graph.hpp                                                  _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 13:20:07 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/17 16:25:05 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include "vector2.hpp"

class Graph{
	private:
		Vector2 size;
		std::vector<Vector2> points;

		bool isInside(const Vector2& point) const;
		
	public:
		Graph(const Vector2& size);

		bool addPoint(const Vector2& point);
		void display() const;		
};

#endif
