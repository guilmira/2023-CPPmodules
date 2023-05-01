/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/30 16:47:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Mutantstack::Mutantstack()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Mutantstack::Mutantstack(std::string const & instance_name)
	: _name(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Mutantstack::~Mutantstack()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Mutantstack::Mutantstack(Mutantstack const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Mutantstack & Mutantstack::operator=(Mutantstack const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setName(rhs.getName());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Mutantstack::getName() const
{
	return (this->_name);
}

void Mutantstack::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void Mutantstack::ilog(const std::string & name, const std::string & msg) const
{
	
	std::cout << "[Class]Mutantstack	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
