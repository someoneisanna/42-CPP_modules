/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:23:46 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/09 09:47:22 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

/*
	Messages:
	1*[19920104_091532] index:0;amount:42;created -> Constructor
	2*[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0 -> displayAccountsInfos
	3*[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0 -> displayStatus
	4*[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 -> makeDeposit
	5*[19920104_091532] index:0;p_amount:47;withdrawal:refused -> makeWithdrawal
	6*[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1 -> makeWithdrawal
	7*[19920104_091532] index:0;amount:47;closed -> Destructor
*/

int main(void)
{
	Account a(42);

	a.displayAccountsInfos();
	a.displayStatus();
	a.makeDeposit(5);
	a.makeWithdrawal(200);
	a.makeWithdrawal(34);
	a.displayStatus();
	a.displayAccountsInfos();
}
