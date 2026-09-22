/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   DivideAndRule.cpp                                          _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/30 11:18:33 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/22 14:30:24 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "DivideAndRule.hpp"
#include "tui.hpp"


Bank::Bank(): liquidity(5000){}
Bank::~Bank(){}

void Bank::delete_account(size_t id){
	std::map<size_t, Account>::iterator it = clientAccounts.find(id);
	if (it == clientAccounts.end())
		throw std::runtime_error("Account does not exist");
	if (it->second.debt > 0)
		throw std::runtime_error("Can't delete account, account has debt");
	if (it->second.value > 0)
		this->liquidity += it->second.value;
	clientAccounts.erase(it);
}

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
	
	drawNewAccountHeader(account);
}

void Bank::give_loan(size_t id, size_t loan){
	// size_t loan = 0;
	// drawLoanHeader();
	// loan = drawLoanFooter(this);
	if (loan > this->liquidity){
		drawLoanWarning();
		throw std::runtime_error("Loan exceeds the bank's liquidity");
	}
	Account &account = (*this)[id];
	account.value += loan;
	account.debt += loan;
	this->liquidity -= loan;
}

void Bank::pay_loan(size_t id, size_t amount){
	// size_t amount = 0;
	
	Account &account = (*this)[id];
	if (amount > account.value)
		throw std::runtime_error("You don't have that amount of money");
	if (account.debt > 0){
		if (account.value == 0){
			drawSharkLoanerHeader();
			amount = 999999;
			account.debt += amount;
			drawSharkLoanerFooter(amount);
			throw std::runtime_error("No money to pay loan");
		}
		
		drawSharkHeader();
		if (amount == 0){
			if (account.debt >= account.value){
				amount = account.value;
				// account.debt -= amount;
			}
			else if (account.debt < account.value){
				amount = account.debt;
				// account.debt -= amount;
			}
		}
		else{
			if (account.debt < amount){
				size_t donation = amount - account.debt;
				this->liquidity += donation;
				account.value -= donation;
				drawDonationv2Header();
				drawDonationFooter(donation);
				amount -= donation;
			}
		}
		account.debt -= amount;
		this->liquidity += amount;
		account.value -= amount;
		drawSharkFooter(amount);
		std::cout << "Press Enter to continue...";
		std::cin.ignore();
		std::cin.get();
	}
	else{
		drawDonationHeader();
		amount = 4545;
		account.debt += amount;
		drawDonationFooter(amount);
		throw std::runtime_error("No debt to pay");
	}

}

void Bank::deposit_money(size_t id, size_t money){
	size_t fee = 0;
	// drawDepositHeader();
	// money = drawDepositFooter();
	Account &account = (*this)[id];

	fee = (money * 5) / 100;
	account.value += money - fee;
	this->liquidity += fee;
}

void Bank::withdraw_money(size_t id, size_t money){
	// size_t money = 0;
	// drawWithdrawHeader();
	// money = drawWithdrawFooter();
	Account &account = (*this)[id];
	if (money > account.value){
		clearScreen();
		throw std::runtime_error("No you can not\n You don\'t have that much money");
	}
	account.value -= money;
}


// TODO: Need to check and handle when receiving id 0 or highers than the ones that exist
Bank::Account& Bank::operator[](size_t id){
	std::map<size_t, Account>::iterator it = clientAccounts.find(id);
	if (it == clientAccounts.end())
		throw std::runtime_error("Account does not exist");
	return (it->second);
}

const Bank::Account& Bank::operator[](size_t id) const{
	std::map<size_t, Account>::const_iterator it = clientAccounts.find(id);
	if (it == clientAccounts.end())
		throw std::runtime_error("Account does not exist");
	return (it->second);
}




// =====================================
//				ACCOUNT

const size_t& Bank::Account::get_id() const{
	return id;
}

const size_t& Bank::Account::get_value() const{
	return value;
}

const size_t& Bank::Account::get_debt() const{
	return debt;
}

const size_t& Bank::get_liquidity() const{
	return liquidity;
}
