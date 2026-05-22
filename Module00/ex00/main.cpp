/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cpp                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/05/22 09:16:55 by jodos-sa                 `----'`         */
/*   Updated: 2026/05/22 11:59:38 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>

#define END		"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"


void	menu()
{
	std::cout << "========================================================================" << std::endl;
	std::cout << "||                              MENU                                  ||" << std::endl;
	std::cout << "||   INSERT -> \"ADD\" TO ADD                                           ||" << std::endl;
	std::cout << "||   INSERT -> \"SEARCH\" TO SEARCH                                     ||" << std::endl;
	std::cout << "||   INSERT -> \"EXIT\" TO EXIT                                         ||" << std::endl;
	std::cout << "========================================================================" << std::endl;
}

int	main()
{
	std::string str;
	
	system("clear");
	menu();
	while (1){
		std::cout << "INSERT HERE -> ";
			std::cin >> str;
			if (std::cin.fail())
				return (std::cout << "\n", 1);
			if (str == "ADD"){
				system("clear");
				menu();
			}
			else if ((str == "SEARCH")){
				system("clear");
				menu();
			}
			else if ((str == "EXIT"))
				break ;
	}
	
	return (0);
}
