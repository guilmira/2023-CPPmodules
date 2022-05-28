/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

Animal::Animal()
	: _type("Default")
{
	log("ANIMAL | Default constructor called.");
	return ;
}

Animal::~Animal()
{
	log("ANIMAL | Destructor called.");
	return ;
}

Animal::Animal(Animal const &src)
{
	log("ANIMAL | Copy constructor called.");
	*this = src;
}

Animal & Animal::operator=(Animal const &rhs)
{
	log("ANIMAL | Assignation operator called.");
	setType(rhs.getType());
	return(*this);
}

std::string const &	Animal::getType(void) const
{
	return(this->_type);
}

void				Animal::setType(const std::string src)
{
	this->_type = src;
}
