/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:04:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 21:17:52 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

#define DEFAULT_WEAPON "simple and jagged bandit knife"

class Weapon
{
	public:

		Weapon();
		~Weapon();
		Weapon(std::string name);

		void		setType(std::string name) { this->_type = name; };
		std::string	getType() const { return (this->_type); };

	private:
		std::string _type;
};

#endif
