/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/30 11:18:33 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/07 16:00:27 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "bank.hpp"

Bank::Bank(): liquidity(0){}
Bank::~Bank(){}

void Bank::create_account(){
	int id = 1;
	Account account;

	std::map<int, Account>::const_iterator it;

	for (it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++){
		if (it->first != id)
			break ;
		id++;
	}

	account.id = id;
	account.value = 0;
	account.debt = 0;
	this->clientAccounts.insert(std::pair<int, Account>(account.id, account));
}

// void Bank::deposit_money(){
// 	
// }


// TODO: Need to check and handle when receiving id 0 or highers than the ones that exist
Bank::Account Bank::operator[](size_t id) const{
	return (this->clientAccounts.at(id));
}



// =====================================
//				ACCOUNT

size_t Bank::Account::get_id() const{
	return id;
}

size_t Bank::Account::get_value() const{
	return value;
}
