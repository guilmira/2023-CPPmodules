/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hola.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 22:18:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Hola.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Hola::Hola()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Hola::Hola(std::string const & instance_name)
	: _name(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Hola::~Hola()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Hola::Hola(Hola const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Hola & Hola::operator=(Hola const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setName(rhs.getName());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Hola::getName() const
{
	return (this->_name);
}

void Hola::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void Hola::ilog(const std::string & name, const std::string & msg) const
{
	
	std::cout << "[Class]Hola	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
