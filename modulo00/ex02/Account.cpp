/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:49:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/21 13:00:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/** CONSTRUCTOR  */
Account::Account()
{
	return ;
}

/** CONSTRUCTOR overload  */
Account::Account(int initial_deposit)
	: _amount(initial_deposit)
{
	Account::_nbAccounts++;
	//std::cout << "overload llamado" << std::endl;
	return ;
}

static void	displayAccountsInfos( void )
{
	//supongo que un dispay de todas las accounts?
	return ; 
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	Account::_totalNbDeposits++;
}