/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/17 12:02:11 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void ft_leaks(void)
{
	system("leaks -q animal");
}

int	main(void)
{
	atexit(ft_leaks);
	//PART 1
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "		DESTRUCTION 1" << std::endl;
	delete j;
	std::cout << "		DESTRUCTION 2" << std::endl;
	delete i;

	}
	std::cout << "----------------------------------------------" << std::endl;

	//PART 2
	{
	Cat miau;
	std::cout << (miau.getBrain())->getIdeas(1) << std::endl;
	Cat second_miau(miau);
	Brain *molde = new Brain;
	molde->setIdeas(1, "hola");
	miau.setBrain(molde);
	std::cout << "//" << std::endl;
	std::cout << (miau.getBrain())->getIdeas(1) << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << (second_miau.getBrain())->getIdeas(1) << std::endl;
	second_miau = miau;
	std::cout << (second_miau.getBrain())->getIdeas(1) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	//PART 3
	{
		Animal *array[6];
		for (int i = 0; i < 3; i++)
			array[i] = new Dog;

		for (int i = 3; i < 6; i++)
			array[i] = new Cat;
		
		array[0]->makeSound();
		array[3]->makeSound();

		for (int i = 0; i < 3; i++)
			delete array[i];

		for (int i = 3; i < 6; i++)
			delete array[i];
	}
	return (0);
}