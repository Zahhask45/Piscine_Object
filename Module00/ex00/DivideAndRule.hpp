/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   DivideAndRule.hpp                                          _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:59:26 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/22 14:04:37 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef DIVIDEANDRULE_HPP
#define DIVIDEANDRULE_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
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
				const size_t& get_value() const;
				const size_t& get_id() const;
				const size_t& get_debt() const;
		};

	private:
		size_t liquidity; // 5% percent of inflow money
		std::map<size_t, Account> clientAccounts;

	public:
		Bank();
		~Bank();
		void create_account();
		void delete_account(size_t id);
		void give_loan(size_t id, size_t loan); // Can't be > liquidity
		void pay_loan(size_t id, size_t loan);
		void deposit_money(size_t id, size_t money);
		void withdraw_money(size_t id, size_t money);

		const size_t& get_liquidity() const;
		
		Account& operator[](size_t id); // Can't use loops
		const Account& operator[](size_t id) const; // Can't use loops
};

#endif
