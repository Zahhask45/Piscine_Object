/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.hpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:59:26 by jodos-sa                 `----'`         */
/*   Updated: 2026/05/22 11:59:37 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Account.hpp"

class Bank {
	public:
		class Account {
			private:
				size_t id;
				size_t value;
		};


	private:
		size_t liquidity; // 5% percent of inflow money
		std::vector<Account *> clientAccounts;

	public:
	
};
