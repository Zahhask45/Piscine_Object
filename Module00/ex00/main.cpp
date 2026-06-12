/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:16:55 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/12 13:02:21 by jodos-sa                                 */
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

	int selected = 0;
	int running = 1;
	int menu = 0;
	int id = 0;

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
			drawAccountHeader(bank[id]);
			std::cout << "\n";

			drawAccountBody(selected);

			std::cout << "\n";
			drawFooter();

			std::cout << "\nSelect option: ";
			std::cin >> selected;

			switch(selected){
				case DEPOSIT:
					// TODO: Create menu for ACCOUNT
					bank.deposit_money(bank[id]);
					break;
				case LOAN:
					// TODO: Create an account and go to account menu
					break;
				case DELETE:
					break;
				case EXIT:
					menu = 0;
					break;		
			}
		}
	}

	return (0);
}
