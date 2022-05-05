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

static int	get_decimal(const int x)
{
	int dec;
	int modifier = 255;

 	dec = x & modifier;


	return (dec);
}

static int store_int_part(int x)
{
	//int modifier = 4294967040; //11111111 11111111 11111111 00000000
	int new_bits;

	new_bits = x << 8; //el numero 3, ahora es el 3 pero sin contar los 8 bits de parte decimal

	return(new_bits);
	
}


std::ostream & operator<<(std::ostream &stream, Fixed const &fixedClass)
{
	int integer_part;
	int decimal_part;
	

	integer_part = fixedClass.getRawBits() >> 8;

	decimal_part = get_decimal(fixedClass.getRawBits());
	
	std::cout << "\n--------Printing class--------" << std::endl;
	std::cout << integer_part << "." << decimal_part << std::endl;
	std::cout << "-----------Print end-----------" << std::endl;
	return (stream);
}

#define DECIMAL_BIT_NBR 8

const int Fixed::_decimalBits = DECIMAL_BIT_NBR;

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}


Fixed::Fixed()
	: _value(0)
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

//32 bits, de los cuales marcamos 8 como decimales.
// 00000000 00000000 00000000 . 00000000
//al guardarse en un int, es siempre un fixed(32,8).
Fixed::Fixed(const int i)
	: _value(i << 8)
{
	//if que no se psa de 24 bits
	log("Int constructor called.");
	return ;
}

int power_to(const int base, const int exponent)
{
	int res;

	res = base;
	for(int i = 0; i < exponent - 1; i++)
		res *= base;

		std::cout << "here " << res << std::endl;
	return (res);
}

int count_mantissa(float fl)
{
	int i;
	int count;

	i = (int) fl;
	count = 0;
	while (i != fl)
	{
		fl *= 10;
		i = (int) fl;
		count++;
	}
	return (count);
}

Fixed::Fixed(const float fl)
{
	int integer_part;
	int decimal_part;

	integer_part = (int) fl;
	this->_value = store_int_part(integer_part);
	//if que no se psa de 24 bits
	log("Float constructor called.");

	int precision ;
	/* precision = count_mantissa(fl);
	std::cout << precision << std::endl; */
	precision = 3;
	decimal_part = (fl - integer_part) * pow(10, precision);
	std::cout << "here " << (fl - integer_part) << std::endl;
	std::cout << "here " << decimal_part << std::endl;

	//this->_value = store_decimal_part(decimal_part);

//make sure decimal part is not bigger than 255
	
	this->_value = (this->_value) | decimal_part;
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
		this->_value = rhs._value;
		return (*this);
	}
	return (*this);
}



int Fixed::getRawBits(void) const
{
	log("getRawBits member fuction called.");
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}