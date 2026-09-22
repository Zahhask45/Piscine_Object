/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tui.cpp                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/06/07 17:17:19 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/22 14:09:38 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "tui.hpp"

#define ENTER	1
#define CREATE	2
#define LOAN	3
#define DELETE	4
#define EXIT	0

const int WIDTH = 36;

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void readOption(size_t &value)
{
	if (std::cin >> value)
		return ;
	clearScreen();
	std::cout << "Trying to be funny\n" << "OUT" << std::endl;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cin.get();
	value = 0;
}

void readSelection(size_t &value)
{
	if (std::cin >> value)
		return ;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	value = 999999;
}


void drawBody(int selected)
{
	const char* menu[] = {
		"1 -> Enter Account",
		"2 -> Create Account",
		"0 -> Exit",
	};

	for (int i = 1; i <= 3; i++)
	{
		if (i == selected && selected != 3)
			std::cout << " > " << menu[i - 1] << " <\n";
		else
			std::cout << "   " << menu[i - 1] << "\n";
		}
}


void drawHeader()
{
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           BANK SYSTEM BANANA         │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

void drawAccountHeader(Bank::Account &account)
{
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           WELCOME USER BANANA        │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	
	std::ostringstream line1;
	line1 << "ID: " << account.get_id();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line1.str() << " │\n";

	std::ostringstream line2;
	line2 << "BALANCE: " << account.get_value();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line2.str() << " │\n";

	std::ostringstream line3;
	line3 << "DEBT: " << account.get_debt();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line3.str() << " │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

void drawAccountBody(int selected)
{
	const char* menu[] = {
		"1 -> Deposit Money",
		"2 -> Withdraw Money",
		"3 -> Ask for Loan",
		"4 -> Pay the Loan",
		"5 -> Delete Account",
		"0 -> Exit"
	};

	for (int i = 1; i <= 6; i++)
	{
		if (i == selected && selected != 6)
			std::cout << " > " << menu[i - 1] << " <\n";
		else
			std::cout << "   " << menu[i - 1] << "\n";
		}
}

void drawFooter()
{
	std::cout << "\n────────────────────────────────────────\n";
	std::cout << "Use numbers to navigate | 0 = exit\n";
}

void drawNewAccountHeader(Bank::Account &account)
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           BANK SYSTEM BANANA         │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│      HOORAY NEW ACCOUNT CREATED      │\n";
	std::ostringstream line1;
	line1 << "ID: " << account.get_id();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line1.str() << " │\n";
	std::cout << "└──────────────────────────────────────┘\n";

	std::cout << "\nPress Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}


void drawLoginHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│                 LOGIN                │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│            WHAT IS THE ID?           │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}


size_t drawLoginFooter()
{
	size_t id = 0;
	
	std::cout << "\n────────────────────────────────────────\n";
	std::cout << "Use numbers for ID | 0 = exit\n";

	std::cout << "\nID: ";
	readOption(id);
	return (id);
}



void drawDepositHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           DEPOSIT USER BANANA        │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│           HOW MUCH TO DEPOSIT        │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}


size_t drawDepositFooter()
{
	size_t money = 0;
	
	std::cout << "\n────────────────────────────────────────\n";
	std::cout << "Use numbers for deposit amount | 0 = exit\n";
	std::cout << "\nMONEY: ";
	readOption(money);
	return (money);
}

void drawWithdrawHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│          WITHDRAW USER BANANA        │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│          HOW MUCH TO WITHDRAW        │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}


size_t drawWithdrawFooter()
{
	size_t money = 0;
	
	std::cout << "\n────────────────────────────────────────\n";
	std::cout << "Use numbers for withdraw amount | 0 = exit\n";
	std::cout << "\nMONEY: ";
	readOption(money);
	return (money);
}

void drawLoanHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           LOAN USER BANANA           │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│       HOW MUCH TO ASK FOR LOAN       │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

size_t drawLoanFooter(Bank *bank)
{
	size_t loan = 0;
	
	std::cout << "Bank Money Amount: " << bank->get_liquidity();
	std::cout << "\n────────────────────────────────────────\n";
	std::cout << "Use numbers for loan amount | 0 = exit\n";
	std::cout << "\nLOAN: ";
	readOption(loan);
	return (loan);
}

void drawLoanWarning()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│            WARNING BANANA            │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│        WE CAN'T LOAN THAT MUCH       │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

void drawSharkHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│             SHARK BANANA             │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│        WE DONT ASK FOR AMOUNT        │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

void drawSharkFooter(size_t amount)
{
	
	std::cout << "\nAmount Paid: " << amount;
	std::cout << "\n────────────────────────────────────────\n";
}

void drawSharkLoanerHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│             SHARK BANANA             │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│        ARE YOU TRYING TO PAY         │\n";
	std::cout << "│            WITHOUT MONEY?            │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│          DEBT IS HIGHER NOW          │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

void drawSharkLoanerFooter(size_t amount)
{
	
	std::cout << "\nAmount Added: " << amount;
	std::cout << "\n────────────────────────────────────────\n";
}

void drawDonationHeader()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│             SHARK BANANA             │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│        ARE YOU TRYING TO PAY         │\n";
	std::cout << "│           INEXISTENT DEBT?           │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│          DEBT IS HIGHER NOW          │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}



void drawDonationFooter(size_t amount)
{
	
	std::cout << "\nAmount Added: " << amount;
	std::cout << "\n────────────────────────────────────────\n";
}

void drawDonationv2Header()
{
	clearScreen();
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│             SHARK BANANA             │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│        THANK YOU FOR THE EXTRA       │\n";
	std::cout << "│                MONEY                 │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}



void drawDonationv2Footer(size_t amount)
{
	
	std::cout << "\nAmount Donated to the Bank: " << amount;
	std::cout << "\n────────────────────────────────────────\n";
}
