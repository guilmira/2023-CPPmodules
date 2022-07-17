/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

Cat::Cat()
	: _pointer(new Brain)
{
	Animal::setType("Covenant cat");
	
	log("Cat | Default constructor called.");
	log("Cat | Mem for brain allocated.");

	return ;
}

Cat::~Cat()
{
	log("Cat | Destructor called.");
	log("Cat | Mem for brain deallocated.");
	delete this->_pointer;
	return ;
}

Cat::Cat(Cat const &src)
	: Animal()
{
	log("Cat | Copy constructor called.");
	*this = src;
}

Cat & Cat::operator=(Cat const &rhs)
{
	log("Cat | Assignation operator called.");
	setType(rhs.getType());

	Brain *new_pointer;
	new_pointer = new Brain(*rhs._pointer); //con el constructor copia de Brain, creo una replica. Para eso está

	this->_pointer = new_pointer;
/* 	for (int i = 0; i < N; i++)
		this->_ideas[i] = out.str(); */

	return(*this);
}

void Cat::makeSound(void) const
{
	log("Cat | Mr. good cat.");
}

const Brain *Cat::getBrain()
{ 
	return (this->_pointer);
}

void Cat::setBrain(Brain *src)
{ 	
	if (this->_pointer)
		delete _pointer;
	this->_pointer = src; 
}