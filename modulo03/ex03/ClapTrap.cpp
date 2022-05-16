/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:31 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 19:28:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	log(std::string const &str)
{
	std::cout << str << std::endl;
}

static void	msg(std::string const &str)
{
	std::cout << str;
}

ClapTrap::ClapTrap()
	: _name("Default"), _hp(10), _mp(10), _dps(0)
{
	log("Default constructor called.");
	return ;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hp(10), _mp(10), _dps(0)
{
	log("Overload constructor called.");
	return ;
}

ClapTrap::~ClapTrap()
{
	log("Destructor called.");
	return ;
}



/* --------------------------------- GET | SET --------------------------------- */
const std::string & ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHp(void) const
{
	return (this->_hp);
}

int ClapTrap::getMp(void) const
{
	return (this->_mp);
}

int ClapTrap::getDps(void) const
{
	return (this->_dps);
}

void ClapTrap::setName(std::string const name)
{
	this->_name = name;
}

void ClapTrap::setHp(int hp)
{
	this->_hp = hp;
}

void ClapTrap::setMp(int mp)
{
	this->_mp = mp;
}

void ClapTrap::setDps(int dps)
{
	this->_dps = dps;
}

/* --------------------------------- CANONIC --------------------------------- */
ClapTrap::ClapTrap(ClapTrap const &src)
{
	log("Copy constructor called.");
	*this = src;
}


ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	log("Assignation operator called.");
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_mp = rhs.getMp();
	this->_dps = rhs.getDps();
	return (*this);
}
/* --------------------------------- METHODS --------------------------------- */
void ClapTrap::attack(std::string const & target)
{
	msg("ClapTrap ");
	msg(getName());
	msg(" attacked ");
	msg(target);
	msg(", causing ");
	std::cout << getDps() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	msg("ClapTrap ");
	msg(getName());
	msg(" takes ");
	std::cout << amount << " points of damage. ";
	if (amount >= (unsigned int) getHp())
		setHp(0);
	else
		setHp(getHp() - amount);
	std::cout << "Current hp: " << getHp() << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	msg("ClapTrap ");
	msg(getName());
	msg(" repairs ");
	std::cout << amount << " points of damage. ";
	setHp(getHp() + amount);
	std::cout << "Current hp: " << getHp() << std::endl;
	this->_mp--;

}