/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:18:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/25 13:15:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
/* Me gustaria saber como se hace esto, especialmente el default contructor
HumanA::HumanA()
	:_name("Stranger")
{
	//this->_weapon_assigned.setType(DEFAULT_WEAPON);
	return ;
}

HumanA::HumanA(std::string& name)
	:_name(name._name),
	_weapon_assigned(??)
{
	
	this->_weapon_assigned = default_weapon;
	return ;
} */

HumanA::HumanA(std::string name, Weapon &weapon1)
	: _name(name), _weapon_assigned(weapon1)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon_assigned.getType();
	std::cout << std::endl;
}