/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:46:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IMateriaSource.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]IMateriaSource - [Instance]" << name << " |	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
IMateriaSource::IMateriaSource()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

IMateriaSource::IMateriaSource(std::string const & instance_name)
	: _name(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
IMateriaSource::~IMateriaSource()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
IMateriaSource::IMateriaSource(IMateriaSource const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
IMateriaSource & IMateriaSource::operator=(IMateriaSource const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->_name = rhs.getName();
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & IMateriaSource::getName() const
{
	return (this->_name);
}

void IMateriaSource::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */

