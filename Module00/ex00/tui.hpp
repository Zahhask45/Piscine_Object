/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tui.hpp                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/06/07 17:20:17 by jodos-sa                 `----'`         */
/*   Updated: 2026/06/07 17:31:33 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef TUI_HPP
#define TUI_HPP

#include "bank.hpp"

struct Bank;

void clearScreen();
void drawBody(int selected);
void drawHeader();
void drawAccountHeader(Bank::Account user);
void drawAccountBody(int selected);
void drawFooter();
void drawNewAccountHeader(Bank::Account *account);

#endif
