/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/09 00:24:30 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
//#include "ICharacter.hpp"
#include "Thief.hpp"
#include "Firaga.hpp"
#include "Esuna.hpp"

void ft_leaks(void)
{
	system("leaks -q materia");
}

int	main(void)
{
	atexit(ft_leaks);
	{

		Thief yitan("Yitán");
		Thief kuja("kuja");
	std::cout << "----------------------------------------------" << std::endl;
		Firaga fire("firaga");
		Esuna esuna("esuna");
	
	std::cout << "----------------------------------------------" << std::endl;
	/* AMateria *fire_ptr;
	fire_ptr = dynamic_cast<AMateria *>(&fire);
	if (!fire_ptr)
    {
        std::cout << "nada" << std::endl;
    }
    else
    {
		std::cout << "funciona" << std::endl;
    } */
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	MateriaSource *ptr;
	ptr = new MateriaSource;
	ptr->learnMateria(&fire);
	ptr->learnMateria(&esuna);
	
	std::cout << "----------------------------------------------" << std::endl;

	AMateria *firaga1;
	AMateria *esuna1;
	firaga1 = ptr->createMateria("firaga");
	esuna1 = ptr->createMateria("esuna");

	yitan.equip(firaga1);
	yitan.use(0, kuja);
	yitan.unequip(1);
	yitan.use(0, kuja);
	yitan.unequip(0);
	yitan.use(0, kuja);
	yitan.equip(firaga1);
	yitan.equip(firaga1);
	yitan.equip(firaga1);
	yitan.equip(firaga1);
	yitan.equip(esuna1);
	yitan.use(1, kuja);
	std::cout << "----------------------------------------------" << std::endl;

	delete firaga1;
	delete esuna1;

	std::cout << "----------------------------------------------" << std::endl;
	delete ptr;


	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "⭕OUTPUT⭕" << std::endl;
	std::cout << "⭕OUTPUT⭕" << std::endl;


	IMateriaSource* src = new MateriaSource();
	Firaga fire("firaga");
	Esuna esuna("esuna");

	src->learnMateria(&fire);
	src->learnMateria(&esuna);
	std::cout << "----------------------------------------------" << std::endl;
	AMateria *c1;
	AMateria *c2;
	AMateria *c3;
	
	c1 = src->createMateria("firaga");
	c2 = src->createMateria("esuna");
	c3 = src->createMateria("ultra gravity");
	c3 = NULL;
	std::cout << "----------------------------------------------" << std::endl;
	ICharacter *squall = new Thief("Squall");
	ICharacter *rinoa = new Thief("Rinoa");
	ICharacter *seif = new Thief("Seifer");
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
	delete c1;
	delete c2;
	delete src;

	return (0);
}