/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:18:22 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 18:07:33 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
	:_name("Stranger"), _weapon_assigned(NULL)
{
	return ;
}

HumanB::HumanB(std::string name)
	:_name(name), _weapon_assigned(NULL)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}


/* 
EXPLICACION: dereference a NULL pointer and you will get undefined behaviour.
en el constructor, los punteros se inicialian a NULL.
Si luego intentas dereferenciar con:
std::cout << this->_weapon_assigned->getType();
(fijate en la flecha), puedes pillar un puntero NULL y al suelo.

if (!this->_weapon_assigned)
	{
		std::cout << this->_name;
		std::cout << " cannot attack; no weapon equiped";
		std::cout << std::endl;
		return ;
	}

 */

void	HumanB::attack(void) const
{
	if (!this->_weapon_assigned)
	{
		std::cout << this->_name;
		std::cout << " cannot attack; no weapon equiped";
		std::cout << std::endl;
		return ;
	}

	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon_assigned->getType();
	std::cout << std::endl;
}