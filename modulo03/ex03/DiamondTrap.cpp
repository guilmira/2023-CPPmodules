/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:48:06 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:05:49 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static void	log(std::string const &str)
{
	std::cout << str << std::endl;
}

static void	msg(std::string const &str)
{
	std::cout << str;
}

DiamondTrap::DiamondTrap()
{
	log("//Diamond default.");
	this->setName("Default diamond name");
	//this->ClapTrap::setName(this->_name.append("_clap_name"));
	this->setHp(FragTrap::getHp());
	this->setMp(ScavTrap::getMp());
	this->setDps(FragTrap::getDps());
	return ;
}

//dont initialize like this : ClapTrap(name.append("_clap_name")), because the append works by reference and it will modify the string.
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap("Default")
{
	std::string copy(name);

	this->setName(name);
	ClapTrap::setName(copy.append("_clap_name"));
	log(this->getName());
	log("//Diamond overload constructor//.");
	log(name);
	this->setHp(FragTrap::getHp());
	this->setMp(ScavTrap::getMp());
	this->setDps(FragTrap::getDps());
	return ;
}

DiamondTrap::~DiamondTrap()
{
	msg(this->getName());
	log("//Diamond Destructor.");
	return ;
}

/* --------------------------------- CANONIC --------------------------------- */
DiamondTrap::DiamondTrap(DiamondTrap const &src)
	: 	ClapTrap(src.getName()), 
		ScavTrap(src.getName()),
		FragTrap(src.getName())

{
	msg(this->getName());
	log("//Diamond copy constructor called.");
	*this = src;
}


DiamondTrap & DiamondTrap::operator=(DiamondTrap const &rhs)
{
	log("//Diamond Assignation.");
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_mp = rhs.getMp();
	this->_dps = rhs.getDps();
	return (*this);
}
/* --------------------------------- METHODS --------------------------------- */
