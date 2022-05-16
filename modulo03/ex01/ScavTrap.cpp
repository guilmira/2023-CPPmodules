/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:31 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 02:05:32 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


static void	log(std::string const &str)
{
	std::cout << str << std::endl;
}

static void	msg(std::string const &str)
{
	std::cout << str;
}

ScavTrap::ScavTrap()
	: _name("Default"), _hp(10), _mp(10), _dps(0)
{
	log("Default constructor called.");
	return ;
}

ScavTrap::ScavTrap(std::string name)
	: _name(name), _hp(10), _mp(10), _dps(0)
{
	log("Overload constructor called.");
	return ;
}

ScavTrap::~ScavTrap()
{
	log("Detructor called.");
	return ;
}

/* --------------------------------- CANONIC --------------------------------- */
ScavTrap::ScavTrap(ScavTrap const &src)
{
	log("Copy constructor called.");
	*this = src;
}


ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	log("Assignation operator called.");
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_mp = rhs.getMp();
	this->_dps = rhs.getDps();
	return (*this);
}
/* --------------------------------- METHODS --------------------------------- */