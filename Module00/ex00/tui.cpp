/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tui.cpp                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/06/07 17:17:19 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/07 17:25:31 by jodos-sa                                 */
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


void drawBody(int selected)
{
	const char* menu[] = {
		"1 -> Enter Account",
		"2 -> Create Account",
		"0 -> Exit"
	};

	for (int i = 1; i < 3; i++)
	{
		if (i == selected)
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

void drawAccountHeader(Bank::Account user)
{
	
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           WELCOME USER BANANA        │\n";
	
	std::ostringstream line1;
	line1 << "ID: " << user.get_id();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line1.str() << " │\n";

	std::ostringstream line2;
	line2 << "BALANCE: " << user.get_value();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line2.str() << " │\n";

	std::ostringstream line3;
	line3 << "DEBT: " << user.get_debt();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line3.str() << " │\n";
	std::cout << "└──────────────────────────────────────┘\n";
}

void drawAccountBody(int selected)
{
	const char* menu[] = {
		"1 -> Deposit Money",
		"2 -> Ask for Loan",
		"3 -> Delete Account",
		"0 -> Exit"
	};

	for (int i = 1; i < 4; i++)
	{
		if (i == selected)
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

void drawNewAccountHeader(Bank::Account *account)
{
	std::cout << "┌──────────────────────────────────────┐\n";
	std::cout << "│           BANK SYSTEM BANANA         │\n";
	std::cout << "├──────────────────────────────────────┤\n";
	std::cout << "│      HOORAY NEW ACCOUNT CREATED      │\n";
	std::ostringstream line1;
	line1 << "ID: " << account->get_id();

	std::cout << "│ " << std::left << std::setw(WIDTH) << line1.str() << " │\n";
	std::cout << "└──────────────────────────────────────┘\n";

	std::cout << "\nPress Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}
