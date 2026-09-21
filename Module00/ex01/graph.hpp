/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   graph.hpp                                                  _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 13:20:07 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/21 14:25:04 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <png.h>
#include "vector2.hpp"

class Graph{
	private:
		Vector2 size;
		std::vector<Vector2> points;
		Vector2 line;

		bool isInside(const Vector2& point) const;
		bool hasPoint(int x, int y) const;
		
	public:
		Graph(const Vector2& size);

		bool addPoint(const Vector2& point);
		void loadPoints(const std::string& filename);
		void display() const;

		const std::vector<Vector2>& getPoints() const;
		const Vector2& getSize() const;

		void calculateLine();
		const Vector2& getLine() const;
};

void generatePNG(const Graph& graph, const std::string& filename);

#endif
