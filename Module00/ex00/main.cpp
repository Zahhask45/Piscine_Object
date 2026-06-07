/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:16:55 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/07 16:06:09 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "bank.hpp"

#define END		"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

#define CREATE 1
#define DEPOSIT 2
#define LOAN 3
#define DELETE 4
#define EXIT 0

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void drawFrame()
{
    std::cout << "+--------------------------------------+\n";
    std::cout << "|           BANK TERMINAL              |\n";
    std::cout << "+--------------------------------------+\n";
}

void drawBody(int selected)
{
    const char* menu[] = {
        "1 -> Create Account",
        "2 -> Deposit Money",
        "3 -> Give Loan",
        "4 -> Delete Account",
        "0 -> Exit"
    };

    for (int i = 1; i < 5; i++)
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
    std::cout << "│           BANK SYSTEM v1             │\n";
    std::cout << "└──────────────────────────────────────┘\n";
}

void drawFooter()
{
    std::cout << "\n────────────────────────────────────────\n";
    std::cout << "Use numbers to navigate | 0 = exit\n";
}

// void	menu()
// {
// 	std::cout << "========================================================================" << std::endl;
// 	std::cout << "||                      WELCOME TO THE BANK                             ||" << std::endl;
// 	std::cout << "||   INSERT -> \"CREATE\" TO CREATE AN ACCOUNT                                           ||" << std::endl;
// 	std::cout << "||   INSERT -> \"SEARCH\" TO SEARCH                                     ||" << std::endl;
// 	std::cout << "||   INSERT -> \"EXIT\" TO EXIT                                         ||" << std::endl;
// 	std::cout << "========================================================================" << std::endl;
// }

int	main()
{
	std::string str;
	Bank bank;
	
	bank.create_account();
	Bank::Account account = bank[1];
	// bank.deposit_money();

	std::cout << account.get_id() << std::endl;

	   int selected = 0;
	       int running = 1;
	   
	       while (running)
	       {
	           clearScreen();
	   
	           drawHeader();
	           std::cout << "\n";
	   
	           drawBody(selected);
	   
	           std::cout << "\n";
	           drawFooter();
	   
	           std::cout << "\nSelect option: ";
	           std::cin >> selected;
	   
	           if (selected == EXIT)
	               running = 0;
	       }
	
	// menu();
	// while (1){
	// 	std::cout << "INSERT HERE -> ";
	// 		std::cin >> str;
	// 		if (std::cin.fail())
	// 			return (std::cout << "\n", 1);
	// 		if (str == "ADD"){
	// 			system("clear");
	// 			menu();
	// 		}
	// 		else if ((str == "SEARCH")){
	// 			system("clear");
	// 			menu();
	// 		}
	// 		else if ((str == "EXIT"))
	// 			break ;
	// }
	
	return (0);
}
