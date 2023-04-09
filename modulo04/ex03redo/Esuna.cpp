/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Esuna.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:46:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Esuna.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	std::cout << "[Class]Esuna	- [Instance]" << name << "	|	"\
	
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Esuna::Esuna()
	: AMateria()
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Esuna::Esuna(std::string const & instance_name)
	: AMateria(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Esuna::~Esuna()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Esuna::Esuna(Esuna const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Esuna & Esuna::operator=(Esuna const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->_name = rhs.getName();
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */

/* --------------------------------- METHODS --------------------------------- */
AMateria *Esuna::clone() const
{
	std::cout << "Cloning materia " << getName() << std::endl;
	return (new Esuna(*this));
}

void Esuna::use(ICharacter & target)
{
	std::cout << getName() << " casted! Healed blindness of " << target.getName() << std::endl;
}