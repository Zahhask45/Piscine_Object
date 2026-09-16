/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.hpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:59:26 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/15 18:06:28 by jodos-sa                                 */
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
#include <stdexcept>

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
		void delete_account(size_t); // Create menu asking for what Account to delete
		void give_loan(size_t id); // Can't be > liquidity
		void deposit_money(size_t id); // Menu asking for what Account to deposit money

		size_t get_liquidity() const;
		
		Account* operator[](size_t id); // Can't use loops
};

#endif
