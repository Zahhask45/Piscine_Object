/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tool.hpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/23 12:34:02 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/23 16:41:40 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
#define TOOL_HPP

class Worker;

// Is Interface or Pure Abstract sadly the name needs to be Tool not ITool
class Tool{
	private:
		Worker* owner;
	protected:
		int numberOfUses;
	public:
		virtual void use() = 0;
		virtual ~Tool();

		Worker* getOwner() const;
		void setOwner(Worker* worker);
};



class Shovel: public Tool{
	public:
		Shovel(int numberOfUses);
		void use();
};

class Hammer: public Tool{
	public:
		Hammer(int numberOfUses);
		void use();
};
#endif
