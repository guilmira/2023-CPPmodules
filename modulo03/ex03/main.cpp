/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/15 16:49:29 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	{
	std::cout << "----------------------------------------------" << std::endl;
	DiamondTrap dmd("DiAmOnD");
	//DiamondTrap dmd(d);

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Parameters of diamond: \n";
	std::cout << dmd.getName() << std::endl;//Name of the atribute _name if diamond.
	std::cout << dmd.ClapTrap::getName() << std::endl;
	std::cout << dmd.getHp() << std::endl;	//Fragtrap: 100
	std::cout << dmd.getMp() << std::endl;	//Scavtrap: 50
	std::cout << dmd.getDps() << std::endl;	//Fragtrap: 30
	std::cout << "----------------------------------------------" << std::endl;	
	dmd.attack("other");
	dmd.whoAmI();
	dmd.guardGate();
	std::cout << "----------------------------------------------" << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;

	return (0);
}