/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   worker.hpp                                                 _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/23 12:23:35 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/23 18:43:22 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
#define WORKER_HPP

#include "position.hpp"
#include "statistic.hpp"
#include <list>

class Tool;
class Workshop;

class Worker{
	private:
		Position coordonnee;
		Statistic stat;
		std::list<Tool*> toolType;
		std::list<Workshop*> workshops;
	public:
		Worker();
		~Worker();
		
		void addTool(Tool *tool);
		void removeTool(Tool *tool);
		void useTools();
		void work();
		
		void registerWorkshop(Workshop* workshop);
		void leaveWorkshop(Workshop* workshop);
		
};

#endif

