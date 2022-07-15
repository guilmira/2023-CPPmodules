/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:31 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/15 16:36:32 by guilmira         ###   ########.fr       */
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
	: _dm_hp(100), _dm_mp(50), _dm_dps(20)
{
	log("-Default constructor called FOR SCAV_TRAP.");
	this->setName("Default");
	this->setHp(_dm_hp);
	this->setMp(_dm_mp);
	this->setDps(_dm_dps);
	return ;
}

ScavTrap::ScavTrap(std::string name)
	: _dm_hp(100), _dm_mp(50), _dm_dps(20)
{
	msg(this->getName());
	log("-Overload constructor called FOR SCAV_TRAP.");
	this->setName(name);
	this->setHp(_dm_hp);
	this->setMp(_dm_mp);
	this->setDps(_dm_dps);
	return ;
}

ScavTrap::~ScavTrap()
{
	msg(this->getName());
	log("-Destructor called FOR SCAV_TRAP.");
	return ;
} 	

/* --------------------------------- CANONIC --------------------------------- */
ScavTrap::ScavTrap(ScavTrap const &src)
	: ClapTrap(src.getName())
{
	msg(this->getName());
	log("-Copy constructor called FOR SCAV_TRAP.");
	*this = src;
}


ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	log("Assignation operator called FOR SCAV_TRAP.");
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_mp = rhs.getMp();
	this->_dps = rhs.getDps();
	return (*this);
}
/* --------------------------------- METHODS --------------------------------- */
void ScavTrap::attack(std::string const & target)
{
	msg("ScavTrap (child) ");
	msg(getName());
	msg(" attacked ");
	msg(target);
	msg(", causing ");
	std::cout << getDps() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	msg(this->getName());
	log(" has entered Gate Keeper mode.");
}
