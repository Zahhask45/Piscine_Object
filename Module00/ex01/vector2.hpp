/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   vector2.hpp                                                _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/17 12:33:11 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/22 13:49:27 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2{
	private:
		float x;
		float y;
		
	public:
		Vector2();
		Vector2(float x, float y);

		const float& getX() const;
		const float& getY() const;
};

#endif
