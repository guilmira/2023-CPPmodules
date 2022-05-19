/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dmd("DiAmOnD.");

dmd.attack("other");
dmd.whoAmI();


	
	

/* 	Very risky and horrible act the DiamondTrap class will declare a private attribute
called name like the one inside ClapTrap.
Its attributes and functions will be chosen from either of its parent classes:
•Name (Parameter of constructor)
•Claptrap::Name (Parameter of constructor + "_clap_name") */
	//dmd.attack("gala");
	//dmd.guardGate();
	return (0);
}