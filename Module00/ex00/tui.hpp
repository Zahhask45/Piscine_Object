/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tui.hpp                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <marvin@42.fr>                             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/06/07 17:20:17 by jodos-sa                 `----'`         */
/*   Updated: 2026/09/16 17:52:38 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef TUI_HPP
#define TUI_HPP

#include "DivideAndRule.hpp"

struct Bank;

void	readOption(size_t &value);
void	readSelection(size_t &selected);
void	clearScreen();
void	drawHeader();
void	drawBody(int selected);
void	drawLoginHeader();
size_t	drawLoginFooter();
void	drawAccountHeader(Bank::Account *account);
void	drawAccountBody(int selected);
void	drawNewAccountHeader(Bank::Account *account);
void	drawFooter();
void	drawDepositHeader();
size_t 	drawDepositFooter();
void	drawWithdrawHeader();
size_t 	drawWithdrawFooter();
void	drawLoanHeader();
size_t 	drawLoanFooter(Bank *bank);
void	drawLoanWarning();
void	drawSharkHeader();
void 	drawSharkFooter(size_t amount);
void	drawSharkLoanerHeader();
void 	drawSharkLoanerFooter(size_t amount);
void	drawDonationHeader();
void 	drawDonationFooter(size_t amount);

#endif
