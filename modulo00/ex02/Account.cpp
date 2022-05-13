/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:49:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/13 09:15:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#define YEARS_MOD 100

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
	this->_displayTimestamp();
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
	this->_displayTimestamp();
	print_value("index", Account::getNbAccounts(), 0);
	print_value("ammount", this->checkAmount(), 0);
	std::cout << "created" << std::endl;
	Account::_totalAmount+= initial_deposit;
	Account::_nbAccounts++;
	return ;
}

Account::~Account()
{
	this->_displayTimestamp();
	print_value("index", this->_accountIndex, 0);
	print_value("ammount", this->checkAmount(), 0);
	std::cout << "closed" << std::endl;
}



void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
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
	this->_displayTimestamp();
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
	Account::_displayTimestamp();
	print_value("accounts", Account::getNbAccounts(), 0);
	print_value("total", Account::getTotalAmount(), 0);
	print_value("deposits", Account::getNbDeposits(), 0);
	print_value("whitdrawals", Account::getNbWithdrawals(), 1);
	return ; 
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	print_value("index", this->_accountIndex, 0);
	print_value("amount", this->checkAmount(), 0);
	print_value("deposits", this->_nbDeposits, 0);
	print_value("whitdrawals", this->_nbWithdrawals, 1);
	return ;
}


void	Account::_displayTimestamp(void)
{
	time_t	current_time;
	tm		*local_time;

	time(&current_time);
	local_time = std::localtime(&current_time);
	std::cout << "[";
	std::cout << "20";
	std::cout << local_time->tm_year - YEARS_MOD;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << local_time->tm_mon + 1 ;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << local_time->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << local_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << local_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << local_time->tm_sec;
	std::cout << "] ";
	return ; 
}

int		Account::checkAmount(void) const
{ 
	return(this->_amount);
}

int	Account::getNbAccounts(void)
{
	return(Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{ 
	return(Account::_totalAmount);
}

int	Account::getNbDeposits(void )
{
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(Account::_totalNbWithdrawals);
}