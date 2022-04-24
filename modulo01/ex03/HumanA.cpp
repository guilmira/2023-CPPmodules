/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:18:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 21:22:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
	:_name("Stranger")
{
	this->_weapon_assigned.setType(DEFAULT_WEAPON);
	return ;
}

HumanA::HumanA(std::string name)
	:_name(name)
{
	this->_weapon_assigned.setType(DEFAULT_WEAPON);
	return ;
}

HumanA::HumanA(std::string name, std::string weapon_name)
	:_name(name), _weapon_assigned(weapon_name)
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