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
	this->setName("Default");
	this->setHp(100);
	this->setMp(100);
	this->setDps(30);
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	msg(this->getName());
	log("//Diamond constructor//.");
	this->setName(name);
	this->setHp(100);
	this->setMp(50);
	this->setDps(20);
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
{
	msg(this->getName());
	log("//Diamond Destructor.");
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
