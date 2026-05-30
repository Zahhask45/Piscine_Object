/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.hpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:59:26 by jodos-sa                 `----'`         */
/*   Updated: 2026/05/30 10:47:47 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

struct Bank {
	public:
		struct Account {
			private:
				size_t id; // Can't have two identical IDs
				size_t value;
			public:
				const size_t get_value();
				const size_t get_id();
		};

	private:
		size_t liquidity; // 5% percent of inflow money
		std::vector<Account *> clientAccounts;

	public:
		Bank();
		~Bank();
		void create_account();
		void edit_account(); // I dont know why?
		void delete_account(); // Create menu asking for what Account to delete
		void give_loan(); // Can't be > liquidity
		void deposit_money(); // Menu asking for what Account to deposit money
		
		Account operator[](size_t id) const; // Can't use loops
};
