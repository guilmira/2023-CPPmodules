/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
PmergeMe::PmergeMe()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

PmergeMe::PmergeMe(std::string const & name)
	: _name(name)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
PmergeMe::~PmergeMe()
{
	ilog(getName(), "-Destroyed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
PmergeMe & PmergeMe::operator=(PmergeMe const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setName(rhs.getName());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & PmergeMe::getName() const
{
	return (this->_name);
}

void PmergeMe::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void PmergeMe::ilog(const std::string & name, const std::string & msg) const
{
	
	std::cout << "[Class]PmergeMe	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
