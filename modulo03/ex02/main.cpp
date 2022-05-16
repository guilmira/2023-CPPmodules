/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 13:46:52 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(void)
{
	ClapTrap slime("SLIME");
	ClapTrap bastard_copy("copy");
	ClapTrap the_true_bastard;

	slime.takeDamage(2);
	the_true_bastard = (bastard_copy = slime);
	the_true_bastard.beRepaired(1);

	FragTrap fragy("RED STRANGE SLIME");
	fragy.beRepaired(1);

	return (0);
}