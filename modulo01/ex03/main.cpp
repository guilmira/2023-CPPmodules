/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 21:14:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void ft_leaks(void)
{
	system("leaks weapons");
}

int	main(void)
{
	//Human A class behaviour
	{
		HumanA	guille("guille", "crossbow");
		HumanA	galazard("Galazard", "Arctic sword");
		HumanA	not_equiped_humanA("OnlyFists");

		guille.attack();
		galazard.attack();
		not_equiped_humanA.attack();
	}

	//Human B class behaviour
	{
		Weapon *ptr;
		HumanB morg;

		ptr = NULL;
		ptr = new Weapon("Malleus Maleficarum");
		morg.setWeapon(ptr);
		morg = HumanB("Morgana");
		morg.attack();
		delete ptr;
	}

	//Human B class unarmed
	{
		Weapon *ptr;
		HumanB alize("Alize Chevalier");

		ptr = NULL;
		alize.attack();
		ptr = new Weapon("Old Hunter´s Shotgun");
		alize.setWeapon(ptr);
		alize.attack();
		delete ptr;
	}

	//atexit(ft_leaks);
	return (0);
}