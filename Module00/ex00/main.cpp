/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:16:55 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/15 18:07:36 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "bank.hpp"
#include "tui.hpp"

#define END		"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

#define ENTER	1
#define CREATE	2
#define DEPOSIT	1
#define LOAN	2
#define DELETE	3
#define EXIT	0

int	main()
{
	Bank bank;

	size_t selected = 0;
	int running = 1;
	int menu = 0;
	size_t id = 0;

	while (running)
	{
		clearScreen();
		if (menu == 0)
		{
			
			drawHeader();
			std::cout << "\n";

			drawBody(selected);

			std::cout << "\n";
			std::cout << "Bank Money Amount: " << bank.get_liquidity();
			drawFooter();

			std::cout << "\nSelect option: ";
			readSelection(selected);
			switch(selected){
				case ENTER:
					// TODO: Create menu for ACCOUNT, LOGIN INTERFACE AND FAIL AND SUCCESSFUL
					drawLoginHeader();
					id = drawLoginFooter();
					if (id == 0)
						break ;
					selected = 0;
					menu = 1;
					break;
				case CREATE:
					// TODO: Create box saying new account created hooray, go to account menu
					bank.create_account();
					menu = 0;
					break;
				case EXIT:
					running = 0;
					break;		
			}
		}
		else
		{
			Bank::Account *account = bank[id];
			if (account == NULL)
			{
				clearScreen();
				std::cout << "Account ID not found.\n";
				std::cout << "Press Enter to return to the main menu...";
				std::cin.ignore();
				std::cin.get();
				menu = 0;
				selected = 0;
				continue ;
			}

			drawAccountHeader(account);
			std::cout << "\n";

			drawAccountBody(selected);

			std::cout << "\n";
			drawFooter();

			std::cout << "\nSelect option: ";
			readSelection(selected);

			switch(selected){
				case DEPOSIT:
					bank.deposit_money(id);
					break;
					case LOAN:
					bank.give_loan(id);
					break;
				case DELETE:
					try{
						bank.delete_account(id);
						menu = 0;
						selected = 0;
					}
					catch {
						std::cout << "Error: " << error.what() << std::endl;
						std::cout << "Press Enter to continue...";
						std::cin.ignore();
						std::cin.get()
					}
				case EXIT:
					menu = 0;
					break;		
			}
		}
	}

	return (0);
}
