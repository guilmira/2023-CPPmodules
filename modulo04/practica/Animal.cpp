/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Animal - [Instance]" << name << " |	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Animal::Animal()
	: _instance_name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Animal::Animal(std::string const & instance_name)
	: _instance_name(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Animal::~Animal()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Animal::Animal(Animal const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Animal & Animal::operator=(Animal const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->_instance_name = rhs.getName();
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Animal::getName() const
{
	return (this->_instance_name);
}

void Animal::setName(std::string name)
{ 
	this->_instance_name = name;
}
/* --------------------------------- METHODS --------------------------------- */

