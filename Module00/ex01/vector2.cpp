/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vector2.cpp                                                _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 13:35:52 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/22 13:53:31 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.hpp"
Vector2::Vector2(): x(0.0f), y(0.0f){}
Vector2::Vector2(float x, float y): x(x), y(y){}

const float& Vector2::getX() const {
	return x;
}

const float& Vector2::getY() const {
	return y;
}
