/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:15:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/04 10:05:59 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define DECIMAL_BIT_NBR 8

const int Fixed::_decimalBits = DECIMAL_BIT_NBR;

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}


Fixed::Fixed()
	: _entero(0)
{
	log("Default constructor called.");
	return ;
}

//COPY CONSTRUCTOR.  THE NAME IS KEY. copy as in, creates a copy, a second object with same values.
//Class SOURCE and the new one just created are NOT the same.
//they dont have the same adress.
//notice how = operator is being used, therefore only contents are copied.
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src; //this is actually operator function being used
	//equivalent to
	//this->operator=(src);
	return ;
}

Fixed::~Fixed()
{
	log("Destructor called.");
	return ;
}


Fixed & Fixed::operator=(Fixed const &rhs)
{
	log("Assignation operator called.");
	if (this != &rhs)
	{
		this->_entero = rhs._entero;
		return (*this);
	}
		
	return (*this);
}



int Fixed::getRawBits(void) const
{
	log("getRawBits member fuction called.");
	return (this->_entero);
}

void Fixed::setRawBits(int const raw)
{
	this->_entero = raw;
}