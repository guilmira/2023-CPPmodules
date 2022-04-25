/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/25 13:23:53 by guilmira         ###   ########.fr       */
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
		Weapon	weapon1("two daggers");
		Weapon	weapon2("Arctic sword");
		Weapon	weapon3("HumanA cannot not have a pointer");
		HumanA	guille("guille", weapon1);
		HumanA	galazard("Galazard", weapon2);
		HumanA	not_equiped_humanA("OnlyFists", weapon3);

		guille.attack();
		galazard.attack();
		not_equiped_humanA.attack();
	}

	//Human B class behaviour
	{
		Weapon weapon_on_stack;
		HumanB morg;

		weapon_on_stack = Weapon("Malleus Maleficarum");
		morg = HumanB("Morgana");
		morg.setWeapon(weapon_on_stack);
		morg.attack();
	}

	//Human B class unarmed
	{
		Weapon *ptr;
		HumanB alize("Alize Chevalier");

		ptr = NULL;
		alize.attack();
		ptr = new Weapon("Old Hunter´s Shotgun");
		alize.setWeapon(*ptr);
		alize.attack();
		delete ptr;
	}

	//prueba A subject
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	//prueba B subject
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	//atexit(ft_leaks);
	return (0);
}