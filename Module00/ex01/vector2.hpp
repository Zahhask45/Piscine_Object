/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vector2.hpp                                                _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 12:33:11 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/17 13:19:45 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2{
	private:
		float x;
		float y;
		
	public:
		Vector2(float x, float y);

		float getX() const;
		float getY() const;
};

#endif
