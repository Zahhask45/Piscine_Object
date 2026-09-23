/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   workshop.hpp                                               _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/09/23 13:13:21 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/23 16:26:18 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <list>

class Worker;

class Workshop{
	private:
		std::list<Worker*> listWorker;
	public:
		void executeWorkDay();
		void registerWorker(Worker* worker);
		void releaseWorker(Worker* worker);
};	

#endif
