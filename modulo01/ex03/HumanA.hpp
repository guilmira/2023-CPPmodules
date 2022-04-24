/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:13:30 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 21:23:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:
		HumanA();
		~HumanA();
		HumanA(std::string name);
		HumanA(std::string name, std::string weapon_name);

		void attack(void) const;

	private:
		std::string _name;
		Weapon _weapon_assigned;

};

#endif