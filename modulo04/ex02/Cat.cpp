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
	this->_pointer = NULL; 
	*this = src;
}
/* This is absolutly necessary as the _pointer could contain trash values,
 therefore when calling overlad = operator the if conndition would be met. */

Cat & Cat::operator=(Cat const &rhs)
{
	Brain *new_pointer;
	
	log("Cat | Assignation operator called.");
	setType(rhs.getType());
	if (this->_pointer)
		delete this->_pointer;
	new_pointer = new Brain(*rhs._pointer); //con el constructor copia de Brain, creo una replica. Para eso está
	this->_pointer = new_pointer;
	return(*this);
}

void Cat::makeSound(void) const
{
	log("Cat | Mr. good cat.");
}

std::string const &	Cat::getType(void) const
{
	return(this->_type);
}

void				Cat::setType(const std::string src)
{
	this->_type = src;
}
