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

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

//FALTA HACER VARIAS PRUEBAS, Y VER CUANDO DA LEAK Y PETA. PRUEBA HA AHCER UN SHALLOW COPY. 
//POR LO DEMAS, EL MAIN ESTARIA
int	main(void)
{
	//PART 1
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
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

	std::cout << (miau.getBrain())->getIdeas(1) << std::endl;
	std::cout << (second_miau.getBrain())->getIdeas(1) << std::endl;
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