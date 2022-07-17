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
	: _pointer(new Brain)
{
	Animal::setType("Syv the pup");
	log("Dog | Default constructor called.");
	log("Dog | Mem for brain allocated.");
	return ;
}

Dog::~Dog()
{
	log("Dog | Destructor called.");
	log("Dog | Mem for brain deallocated.");
	delete this->_pointer;
	return ;
}

Dog::Dog(Dog const &src)
	: Animal()
{
	log("Dog | Copy constructor called.");
	this->_pointer = NULL; 
	*this = src;
}

Dog & Dog::operator=(Dog const &rhs)
{
	Brain *new_pointer;

	log("Dog | Assignation operator called.");
	setType(rhs.getType());
	if (this->_pointer)
		delete this->_pointer;
	new_pointer = new Brain(*rhs._pointer); //con el constructor copia de Brain, creo una replica. Para eso está
	this->_pointer = new_pointer;
	return(*this);
}

void Dog::makeSound(void) const
{
	log("Dog | Be as it may, im Mr. Bad dog.");
}