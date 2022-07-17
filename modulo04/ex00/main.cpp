/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/17 07:50:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	const WrongAnimal* w_i = new WrongCat();
	std::cout << std::endl;


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << w_i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	w_i->makeSound(); //here the difference will appear. The function at base isn't virtual, therefore it isnt overwritten, and the Animal::makesound is the one that is called.
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	std::cout << std::endl;	
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	std::cout << "And the most important:" << std::endl;
	std::cout << "It does not have a virtual destructor, so it only calls the WrongAnimal destructor." << std::endl;
	std::cout << "It doesnt call the WrongCat destructor, and this could easily give memory leaks." << std::endl;
	delete w_i;

	return (0);
}