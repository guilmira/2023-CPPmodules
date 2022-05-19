/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:34:52 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:07:10 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

static void	log(std::string const &str)
{
	std::cout << str << std::endl;
}

static void	msg(std::string const &str)
{
	std::cout << str;
}

FragTrap::FragTrap()
{
	log("-Default constructor called for FragTrap.");
	this->setName("Default");
	this->setHp(100);
	this->setMp(100);
	this->setDps(30);
	return ;
}

FragTrap::FragTrap(std::string name)
{
	msg(this->getName());
	log("-Overload constructor called for FragTrap.");
	this->setName(name);
	this->setHp(100);
	this->setMp(100);
	this->setDps(30);
	return ;
}

FragTrap::~FragTrap()
{
	msg(this->getName());
	log("-Destructor called for FragTrap.");
	return ;
}

/* --------------------------------- CANONIC --------------------------------- */
FragTrap::FragTrap(FragTrap const &src)
	: ClapTrap(getName())
{
	msg(this->getName());
	log("-Copy constructor called for FragTrap.");
	*this = src;
}


FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
	log("Assignation operator called for FragTrap.");
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_mp = rhs.getMp();
	this->_dps = rhs.getDps();
	return (*this);
}
/* --------------------------------- METHODS --------------------------------- */
void FragTrap::attack(std::string const & target)
{
	msg("FragTrap (child) ");
	msg(getName());
	msg(" attacked ");
	msg(target);
	msg(", causing ");
	std::cout << getDps() << " points of damage!" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	msg(this->getName());
	log(" gives you a high five.");
}