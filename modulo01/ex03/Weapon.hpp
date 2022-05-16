/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:04:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 19:31:33 by guilmira         ###   ########.fr       */
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

		void				setType(std::string name);
		std::string	const & getType() const;

	private:
		std::string _type;
};

#endif
