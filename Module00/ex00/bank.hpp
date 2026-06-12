/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.hpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:59:26 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/12 13:02:16 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <map>

struct Bank {
	public:
		struct Account {
			friend struct Bank;
			
			private:
				size_t id; // Can't have two identical IDs
				size_t value;
				size_t debt;
			public:
				size_t get_value() const;
				size_t get_id() const;
				size_t get_debt() const;
		};

	private:
		size_t liquidity; // 5% percent of inflow money
		std::map<size_t, Account> clientAccounts;

	public:
		Bank();
		~Bank();
		void create_account();
		void edit_account(); // I dont know why?
		void delete_account(); // Create menu asking for what Account to delete
		void give_loan(); // Can't be > liquidity
		void deposit_money(size_t id, size_t amount); // Menu asking for what Account to deposit money
		
		const Account* operator[](size_t id) const; // Can't use loops
};

#endif
