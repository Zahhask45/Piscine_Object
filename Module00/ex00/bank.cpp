/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/30 11:18:33 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/12 13:02:14 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "tui.hpp"
#include "bank.hpp"

const int WIDTH = 36;

Bank::Bank(): liquidity(0){}
Bank::~Bank(){}

void Bank::create_account(){
	int id = 1;
	Account account;

	std::map<int, Account>::const_iterator it;

	for (it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++){
		if (it->first != id)
			break ; // 
		id++;
	}

	account.id = id;
	account.value = 0;
	account.debt = 0;
	this->clientAccounts.insert(std::pair<int, Account>(account.id, account));
	
	drawNewAccountHeader(&account);
}

void Bank::deposit_money(Bank::Account &account){
	account.value = 100;
}


// TODO: Need to check and handle when receiving id 0 or highers than the ones that exist
const Bank::Account* Bank::operator[](size_t id) const{
	std::map<size_t, Account>::iterator it = clientAccounts.find(id);
	if (it == clientAccounts.end())
		return NULL;
	return &(it->second);
}



// =====================================
//				ACCOUNT

size_t Bank::Account::get_id() const{
	return id;
}

size_t Bank::Account::get_value() const{
	return value;
}

size_t Bank::Account::get_debt() const{
	return debt;
}
