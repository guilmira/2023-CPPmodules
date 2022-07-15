/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:48:21 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/15 17:15:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

/* LIBRARIES */
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap & operator=(DiamondTrap const &rhs);

		void whoAmI() const;
		void attack(std::string const & target);
		void setName(std::string const name);
		const std::string & getName(void) const;

	private:
		std::string _name;
};

#endif