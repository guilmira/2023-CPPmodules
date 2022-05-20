/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

Cat::Cat()
{
	Animal::setType("Covenant cat");
	log("Cat | Default constructor called.");
	return ;
}

Cat::~Cat()
{
	log("Cat | Destructor called.");
	return ;
}

Cat::Cat(Cat const &src)
	: Animal()
{
	log("Cat | Copy constructor called.");
	*this = src;
}

Cat & Cat::operator=(Cat const &rhs)
{
	log("Cat | Assignation operator called.");
	setType(rhs.getType());
	return(*this);
}

void Cat::makeSound(void) const
{
	log("Cat | Mr. good cat.");
}