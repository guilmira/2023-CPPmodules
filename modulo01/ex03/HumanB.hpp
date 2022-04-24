/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:13:30 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 21:23:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
	public:
		HumanB();
		~HumanB();
		HumanB(std::string name);

		void attack(void) const;
		void setWeapon(Weapon *ptr) { this->_weapon_assigned = ptr; }
	
	private:
		std::string _name;
		Weapon *_weapon_assigned;

};

#endif