/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/18 09:48:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include "Fighter.hpp"

void ft_leaks(void)
{
	system("leaks -q materia");
}

int	main(void)
{
	atexit(ft_leaks);
	//Test 1
	{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "----------------------------------------------" << std::endl;
	AMateria *c1;
	AMateria *c2;
	AMateria *c3;
	
	c1 = src->createMateria(ICE);
	c2 = src->createMateria(CURE);
	c3 = src->createMateria(FIRA);
	c3 = NULL;
	std::cout << "----------------------------------------------" << std::endl;
	ICharacter *squall = new Fighter("Squall");
	ICharacter *rinoa = new Fighter("Rinoa");
	ICharacter *seif = new Fighter("Seifer");
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Battle theme plays on the background\n";
	squall->equip(c2);
	squall->equip(c1);
	std::cout << "----------------------------------------------" << std::endl;
	squall->use(1, *seif);
	squall->unequip(1);
	squall->use(1, *seif);
	rinoa->equip(c2);
	seif->equip(c1);
	seif->use(0, *squall);
	rinoa->use(0, *squall);
	rinoa->use(0, *rinoa);
	rinoa->unequip(1);
	rinoa->unequip(0);
	rinoa->use(0, *seif);
	rinoa->use(4, *seif);
	rinoa->equip(c1);
	rinoa->use(0, *seif);
	std::cout << "Play victory fanfare\n";
	std::cout << "----------------------------------------------" << std::endl;
	delete squall;
	delete rinoa;
	delete seif;
	delete src;
	delete c1;
	delete c2;
	std::cout << "----------------------------------------------" << std::endl;
	}
	return (0);
}