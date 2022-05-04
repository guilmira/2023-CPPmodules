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

const int Fixed::_enteroConst = DECIMAL_BIT_NBR;

Fixed::Fixed()
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &fixed1)
{
	std::cout << "Copy constructor called." << std::endl;
	std::cout << "Class origin and source are actually the same. Indistinguishable." << std::endl;
	*this = fixed1;
	return ;
}

Fixed::~Fixed()
{
	return ;
}


Fixed & Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		//igualar todas las privadas.
		return ;
	}
		
	return (*this);
}

Example::Example()
{
	this->x = 5;
	return ;
}

Example::Example(Example const &src)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return ;
}

//basicamente, =, es cambiar el puntero this. (POR SUPUESTO, no cte.)
Example & Example::operator=(Example const &rhs)
{
	std::cout << "ASSIGNMENT called." << std::endl;

	if (this != &rhs)
		this->x = rhs.x;
	
	return (*this);
	
}

Example::~Example()
{
	return ;
}