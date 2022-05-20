/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

WrongCat::WrongCat()
{
	WrongAnimal::setType("WrongCat default name type. There are not two variables named _type.");
	log("WrongCat | Default constructor called.");
	return ;
}

WrongCat::~WrongCat()
{
	log("WrongCat | Destructor called.");
	return ;
}

WrongCat::WrongCat(WrongCat const &src)
	: WrongAnimal()
{
	log("WrongCat | Copy constructor called.");
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const &rhs)
{
	log("WrongCat | Assignation operator called.");
	setType(rhs.getType());
	return(*this);
}

void WrongCat::makeSound(void) const
{
	log("WrongCat | Mr. good WrongCat.");
}