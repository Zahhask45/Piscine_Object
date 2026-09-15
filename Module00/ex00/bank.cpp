/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   bank.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/30 11:18:33 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/15 18:07:24 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "tui.hpp"
#include "bank.hpp"

Bank::Bank(): liquidity(5000){}
Bank::~Bank(){}

void Bank::create_account(){
	size_t id = 1;
	Account account;

	std::map<size_t, Account>::const_iterator it;

	for (it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++){
		if (it->first != id)
			break ;
		id++;
	}

	account.id = id;
	account.value = 0;
	account.debt = 0;
	this->clientAccounts.insert(std::pair<size_t, Account>(account.id, account));
	
	drawNewAccountHeader(&account);
}

void Bank::deposit_money(size_t id){
	size_t money = 0;
	drawDepositHeader();
	money = drawDepositFooter();
	Account *account = (*this)[id];
	account->value += money * 0.95;
	this->liquidity += money * 0.05;
}


// TODO: Need to check and handle when receiving id 0 or highers than the ones that exist
Bank::Account* Bank::operator[](size_t id){
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

size_t Bank::get_liquidity() const{
	return liquidity;
}
