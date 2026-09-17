/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vector2.cpp                                                _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 13:35:52 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/17 13:38:29 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.hpp"

Vector2::Vector2(float x, float y): x(x), y(y){}

float Vector2::getX() const {
	return x;
}

float Vector2::getY() const {
	return y;
}
