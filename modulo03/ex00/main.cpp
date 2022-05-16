/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 01:41:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap slime("Slime");
	ClapTrap slime_copy(slime);
	ClapTrap black_slime;
	
	slime.attack("galazard");
	slime.beRepaired(1);
	slime.takeDamage(5);
	black_slime = slime;
	black_slime.setName("blackie");
	slime.takeDamage(100);
	black_slime.takeDamage(1);
	return (0);
}