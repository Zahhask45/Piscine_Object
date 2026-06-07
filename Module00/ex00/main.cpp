/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:16:55 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/07 17:30:19 by jodos-sa                                 */
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
#define LOAN	3
#define DELETE	4
#define EXIT	0

int	main()
{
	Bank bank;
	Bank::Account account;

	int selected = 0;
	int running = 1;
	int menu = 0;

	while (running)
	{
		clearScreen();
		if (menu == 0)
		{
			
			drawHeader();
			std::cout << "\n";

			drawBody(selected);

			std::cout << "\n";
			drawFooter();

			std::cout << "\nSelect option: ";
			std::cin >> selected;

			switch(selected){
				case ENTER:
					// TODO: Create menu for ACCOUNT
					// bank.create_account();
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
			drawAccountHeader(account);
			std::cout << "\n";

			drawBody(selected);

			std::cout << "\n";
			drawFooter();

			std::cout << "\nSelect option: ";
			std::cin >> selected;

			switch(selected){
				case ENTER:
					// TODO: Create menu for ACCOUNT
					// bank.create_account();
					break;
				case CREATE:
					// TODO: Create an account and go to account menu
					break;
				case EXIT:
					menu = 0;
					break;		
			}
		}
	}

	return (0);
}
