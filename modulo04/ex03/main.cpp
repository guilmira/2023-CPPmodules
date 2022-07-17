/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/17 13:33:44 by guilmira         ###   ########.fr       */
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
	//Fighter class should only be use through materia created on MateriaSource.
	//That way, its avoided that user declares the materia on stack and within fighter, we free stack allocated variables.
	std::cout << "----------------------------------------------" << std::endl;
	ICharacter *squall = new Fighter("Squall");
	ICharacter *rinoa = new Fighter("Rinoa");
	ICharacter *seif = new Fighter("Seifer");
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Battle theme plays on the background\n";
	squall->equip(c1);
	squall->equip(c2);
	rinoa->equip(c2);
	seif->equip(c1);
	squall->use(0, *seif);
	seif->use(0, *squall);
	rinoa->use(0, *squall);
	rinoa->use(0, *rinoa);
	rinoa->unequip(1);
	rinoa->unequip(0);
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