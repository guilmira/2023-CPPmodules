/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/15 17:14:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

/* LIBRARIES */
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

/* virtual public ClapTrap : Explanation. Its specific of C++.
Is literally meant to be applied in the diamond problem.
Its saying, do not duplicate the ClapTrap class when creating a diamond class. */
class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		virtual ~ScavTrap();
		ScavTrap(ScavTrap const &src);
		ScavTrap & operator=(ScavTrap const &rhs);

		void attack(std::string const & target);
		void guardGate(void);

		protected:
			int _dm_hp;
			int _dm_mp;
			int _dm_dps;
};

#endif