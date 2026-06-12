/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tui.hpp                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/06/07 17:20:17 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/12 13:02:20 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef TUI_HPP
#define TUI_HPP

#include "bank.hpp"

struct Bank;

void	clearScreen();
void	drawHeader();
void	drawBody(int selected);
void	drawLoginHeader();
int		drawLoginFooter();
void	drawAccountHeader(Bank::Account *user);
void	drawAccountBody(int selected);
void	drawNewAccountHeader(Bank::Account *account);
void	drawFooter();

#endif
