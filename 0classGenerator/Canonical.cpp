/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Canonical.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/04 13:33:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Canonical.hpp"

/* CLASS DEFINITION. 
	Index:
	defines
	constructor and destructor
	copy and asign operation
	logs
	overload
*/

//[Class]Fighter - [Instance]_instance_name	| msg

/* static void log(const std::string & msg)
{
	std::cout << msg << std::endl;
} */

static void deep_log(const std::string & name, const std::string & msg)
{
	std::cout << name << msg << std::endl;
}

/* --------------------------------- CONSTRUCTOR --------------------------------- */

Canonical::Canonical()
	: _instance_name("Default instance")
{
	deep_log(getName(), "constructed.");
	return ;
}

Canonical::Canonical(std::string const & instance_name)
	: _instance_name(instance_name)
{
	deep_log(getName(), "overload constructed.");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */

Canonical::~Canonical()
{
	deep_log(getName(), "object destructed.");
	return ;
}
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */

Canonical::Canonical(Canonical const &src)
{
	*this = src;
	deep_log(getName(), "copy constructed.");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Canonical & Canonical::operator=(Canonical const &rhs)
{
	deep_log(getName(), "assgined operator called.");
	if (this != &rhs)
	{
		this->_instance_name = rhs.getName();
	}
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Canonical::getName() const
{
	return (this->_instance_name);
}

void Canonical::setName(std::string name)
{ 
	this->_instance_name = name;
}
/* --------------------------------- METHODS --------------------------------- */

