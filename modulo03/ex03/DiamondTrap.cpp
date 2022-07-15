/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:48:06 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/15 16:49:02 by guilmira         ###   ########.fr       */
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
	this->setHp(FragTrap::_dm_hp);
	this->setMp(ScavTrap::_dm_mp);
	this->setDps(FragTrap::_dm_dps);
	return ;
}

//dont initialize like this : ClapTrap(name.append("_clap_name")), because the append works by reference and it will modify the string.
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap("Default")
{
	std::string copy(name);

	this->setName(name);
	ClapTrap::setName(copy.append("_clap_name"));
	log("//Diamond overload constructor//.");
	this->setHp(FragTrap::_dm_hp);
	this->setMp(ScavTrap::_dm_mp);
	this->setDps(FragTrap::_dm_dps);
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
	std::string copy(rhs.getName());

	log("//Diamond Assignation.");
	this->_name = rhs.getName();
	ClapTrap::setName(copy.append("_clap_name"));
	this->_hp = rhs.getHp();
	this->_mp = rhs.getMp();
	this->_dps = rhs.getDps();
	return (*this);
}
/* --------------------------------- METHODS --------------------------------- */

void DiamondTrap::whoAmI() const
{
	std::cout << "I am " << this->getName();
	std::cout << ". I come from ClapTrap " << this->ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::setName(std::string const name)
{
	this->_name = name;
}

//literal la clave es PONER SU PROPIO GET NAME
	//si no lo pones, usa el get name de Clap y termina sacando el valor de clap.
const std::string & DiamondTrap::getName(void) const
{
	return (this->_name);
}