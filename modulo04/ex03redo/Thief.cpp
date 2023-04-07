/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thief.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:46:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Thief.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Thief - [Instance]" << name << " |	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Thief::Thief()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	for (int i = 0; i < MAX_MATERIA; i++)
		inventory[i] = NULL;
	return ;
}

Thief::Thief(std::string const & instance_name)
	: _name(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	for (int i = 0; i < MAX_MATERIA; i++)
		inventory[i] = NULL;
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Thief::~Thief()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Thief::Thief(Thief const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Thief & Thief::operator=(Thief const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
	{
		this->_name = rhs.getName();
/* 	for (int i = 0; i < MAX_MATERIA; i++)
		inventory[i] = rhs.inventory[i]->clone(); */

	}
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Thief::getName() const
{
	return (this->_name);
}

void Thief::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */

void Thief::equip(AMateria *m)
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{		
		if (inventory[i])
			inventory[i] = m;
	}

}
void Thief::unequip(int idx)
{
	inventory[idx] = NULL;
}
void Thief::use(int idx, ICharacter& target)
{
	std::cout << getName() << "concentrates... ";
	inventory[idx]->use(target);
}


//probar lo de intentar invocar funciones de firaga tratanolo como un Amateria *. No deberia dejar y por eso es safe el casteo