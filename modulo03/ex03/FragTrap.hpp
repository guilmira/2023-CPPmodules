/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:34:15 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/15 16:38:17 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

/* LIBRARIES */
#include "ClapTrap.hpp"

/* virtual public ClapTrap : Explanation. Its specific of C++.
Is literally meant to be applied in the diamond problem.
Its saying, do not duplicate the ClapTrap class when creating a diamond class. */
class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap const &src);
		FragTrap & operator=(FragTrap const &rhs);

		void attack(std::string const & target);
		void highFiveGuys(void);
	
	protected:
		int _dm_hp;
		int _dm_mp;
		int _dm_dps;
};

#endif