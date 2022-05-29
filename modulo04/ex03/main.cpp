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

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include "Fighter.hpp"

//FALTA PASAR LEAKS
int	main(void)
{
	//Test 1
	{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "----------------------------------------------" << std::endl;
	AMateria *c1 = src->createMateria(ICE);
	AMateria *c2 = src->createMateria(FIRA);
	c2 = (AMateria *) c2;
	AMateria *c3 = src->createMateria(CURE);
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
	squall->equip(c3);
	rinoa->equip(c3);
	seif->equip(c1);
	squall->use(0, *seif);
	seif->use(0, *squall);
	rinoa->use(0, *squall);
	rinoa->use(0, *rinoa);
	rinoa->unequip(1);
	rinoa->unequip(0);
	rinoa->equip(c1);
	rinoa->use(0, *seif);
	std::cout << "Play vicotry fanfare\n";
	std::cout << "----------------------------------------------" << std::endl;
	delete squall;
	delete seif;
	delete src;
	delete c1;
	delete c3;
	std::cout << "----------------------------------------------" << std::endl;
	}

	return (0);
}