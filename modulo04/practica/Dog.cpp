/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Dog - [Instance]" << name << " |	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Dog::Dog()
	: Animal(), brain_ptr(new Brain)
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Dog::Dog(std::string const & instance_name)
	: Animal(instance_name), brain_ptr(new Brain)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Dog::~Dog()
{
	ilog(getName(), "-Destructed⭕");
	delete brain_ptr;
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Dog::Dog(Dog const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Dog & Dog::operator=(Dog const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->_instance_name = rhs.getName();
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
/* std::string const & Dog::getName() const
{
	return (this->_instance_name);
}

void Dog::setName(std::string name)
{ 
	this->_instance_name = name;
} */
/* --------------------------------- METHODS --------------------------------- */

