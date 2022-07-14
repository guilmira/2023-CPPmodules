/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/14 12:19:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

aqui estoy revisando
//PENDIENTE
//ademas falta pedir ayuda de las flags raras de compilacion
int	main(void)
{
	DiamondTrap dmd("DiAmOnD.");

	dmd.attack("other");
	dmd.whoAmI();
	//dmd.attack("gala");
	//dmd.guardGate();
	return (0);
}