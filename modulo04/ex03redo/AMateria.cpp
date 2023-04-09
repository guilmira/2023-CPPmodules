/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	std::cout << "[Class]AMateria	- [Instance]" << name << "	|	"\
	
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
AMateria::AMateria()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

AMateria::AMateria(std::string const & name)
	: _name(name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
AMateria::~AMateria()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
AMateria::AMateria(AMateria const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
AMateria & AMateria::operator=(AMateria const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->_name = rhs.getName();
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & AMateria::getName() const
{
	return (this->_name);
}

void AMateria::setName(std::string &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
void AMateria::use(ICharacter & target)
{
	std::cout << getName() << "not casted! Does not exist." << target.getName() << std::endl;
}
