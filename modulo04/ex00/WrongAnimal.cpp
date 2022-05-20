/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

WrongAnimal::WrongAnimal()
	: _type("Default")
{
	log("WrongAnimal | Default constructor called.");
	return ;
}

WrongAnimal::~WrongAnimal()
{
	log("WrongAnimal | Destructor called.");
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	log("WrongAnimal | Copy constructor called.");
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rhs)
{
	log("WrongAnimal | Assignation operator called.");
	setType(rhs.getType());
	return(*this);
}

std::string const &	WrongAnimal::getType(void) const
{
	return(this->_type);
}

void				WrongAnimal::setType(const std::string src)
{
	this->_type = src;
}

void WrongAnimal::makeSound(void) const
{
	log("WrongAnimal | -");
}