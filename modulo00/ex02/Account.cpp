/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:49:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/21 19:31:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	print_value(std::string const &str, int value, int endline)
{
	std::cout << str << ":";
	std::cout << value;
	if (endline)
		std::cout << std::endl;
	else
		std::cout << ";";
}

/** CONSTRUCTOR  */
Account::Account()
	:	_amount(0),
		_accountIndex(Account::_nbAccounts),
		_nbDeposits(0), _nbWithdrawals(0)
{
	print_value("index", Account::getNbAccounts(), 0);
	print_value("ammount", this->checkAmount(), 0);
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
	return ;
}

/** CONSTRUCTOR overload  */
Account::Account(int initial_deposit)
	:	_amount(initial_deposit), 
		_accountIndex(Account::_nbAccounts),
		_nbDeposits(0), _nbWithdrawals(0)
{
	print_value("index", Account::getNbAccounts(), 0);
	print_value("ammount", this->checkAmount(), 0);
	std::cout << "created" << std::endl;
	Account::_totalAmount+= initial_deposit;
	Account::_nbAccounts++;
	return ;
}

Account::~Account()
{
	print_value("index", this->_accountIndex, 0);
	print_value("ammount", this->checkAmount(), 0);
	std::cout << "closed" << std::endl;
}



void Account::makeDeposit(int deposit)
{
	print_value("index", this->_accountIndex, 0);
	print_value("p_amount", this->checkAmount(), 0);
	print_value("deposit", deposit, 0);
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount+= deposit;
	print_value("amount", this->checkAmount(), 0);
	print_value("nb_deposits", this->_nbDeposits, 1);
}

bool Account::makeWithdrawal(int withdrawal)
{
	
	print_value("index", this->_accountIndex, 0);
	print_value("p_amount", this->checkAmount(), 0);
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (1);
	}
	print_value("withdrawal", withdrawal, 0);
	Account::_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount-= withdrawal;
	print_value("amount", this->checkAmount(), 0);
	print_value("nb_withdrawal", this->_nbWithdrawals, 1);
	return (0);
}

void	Account::displayAccountsInfos(void)
{
	
	print_value("accounts", Account::getNbAccounts(), 0);
	print_value("total", Account::getTotalAmount(), 0);
	print_value("deposits", Account::getNbDeposits(), 0);
	print_value("whitdrawals", Account::getNbWithdrawals(), 1);
	return ; 
}

void	Account::displayStatus(void) const
{
	print_value("index", this->_accountIndex, 0);
	print_value("amount", this->checkAmount(), 0);
	print_value("deposits", this->_nbDeposits, 0);
	print_value("whitdrawals", this->_nbWithdrawals, 1);
	return ;
}

void	Account::_displayTimestamp(void)
{
	return ; 
}