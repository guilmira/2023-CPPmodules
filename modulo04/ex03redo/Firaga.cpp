/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Firaga.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:46:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Firaga.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Firaga	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Firaga::Firaga()
	: AMateria()
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Firaga::Firaga(std::string const & instance_name)
	: AMateria(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Firaga::~Firaga()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Firaga::Firaga(Firaga const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Firaga & Firaga::operator=(Firaga const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->_name = rhs.getName();
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */

/* --------------------------------- METHODS --------------------------------- */
AMateria *Firaga::clone() const
{
	std::cout << "Cloning materia " << getName() << std::endl;
	return (new Firaga(*this));
}

void Firaga::use(ICharacter & target)
{
	std::cout << getName() << " casted! A firey tornado flies towards " << target.getName() << std::endl;
}
