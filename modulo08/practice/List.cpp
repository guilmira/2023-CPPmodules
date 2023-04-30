/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 22:18:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "List.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
List::List()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

List::List(std::string const & instance_name)
	: _name(instance_name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
List::~List()
{
	ilog(getName(), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
List::List(List const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
List & List::operator=(List const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setName(rhs.getName());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & List::getName() const
{
	return (this->_name);
}

void List::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void List::ilog(const std::string & name, const std::string & msg) const
{
	
	std::cout << "[Class]List	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
