/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

Dog::Dog()
{
	Animal::setType("Syv the pup");
	log("Dog | Default constructor called.");
	return ;
}

Dog::~Dog()
{
	log("Dog | Destructor called.");
	return ;
}

Dog::Dog(Dog const &src)
	: Animal()
{
	log("Dog | Copy constructor called.");
	*this = src;
}

Dog & Dog::operator=(Dog const &rhs)
{
	log("Dog | Assignation operator called.");
	setType(rhs.getType());
	return(*this);
}



void Dog::makeSound(void) const
{
	log("Dog | Be as it may, im Mr. Bad dog.");
}