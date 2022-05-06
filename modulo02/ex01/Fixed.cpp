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

const int Fixed::_decimalBits = DECIMAL_BIT_NBR;

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

/* --------------------------------- OVERLOAD OUTPUT-STREAM --------------------------------- */
//modifier 8 times = yields 255 (1111 1111). Activates every bit the number specified on the loop.
static int	get_decimal(const int x, const int decimal_bits)
{
	int dec;
	int modifier;

	modifier = 0;
	for (int i = 0; i < decimal_bits; i++)
	{
		if (i != 0)
			modifier = modifier << 1;
		modifier = 1 | modifier;
	}
 	dec = x & modifier;
	return (dec);
}

static int	get_integer(const int x, const int decimal_bits)
{
	int integer;
	int offset;

	offset = decimal_bits;
 	integer = x >> offset;
	return (integer);
}

std::ostream & operator<<(std::ostream &stream, Fixed const &fixedClass)
{
	int integer_part;
	int decimal_part;
	
	integer_part = get_integer(fixedClass.getRawBits(), DECIMAL_BIT_NBR);
	decimal_part = get_decimal(fixedClass.getRawBits(), DECIMAL_BIT_NBR);
	std::cout << integer_part << "." << decimal_part << std::endl;
	return (stream);
}

/* --------------------------------- INT CONST --------------------------------- */
static int parser(const int i)
{
	if (i > LIMITmax_23bit || i < LIMITmin_23bit)
	{
		log("invalid int. Beyond limits");
		return (1);
	}
	return (0);
}

static int parser2(const int i)
{
	if (i > dec_LIMITunsigned_8bit || i < 0)
	{
		log("invalid decimal part. Beyond limits");
		return (1);
	}
	return (0);
}

//32 bits, de los cuales marcamos 8 como decimales. 	00000000 00000000 00000000 . 00000000
//al guardarse en un int, es siempre un fixed(32,8).  	value is initialized to avoid seg faults before parser
Fixed::Fixed(const int i)
	: _value(0)
{
	if (parser(i))
		return ;
	this->_value = i << Fixed::_decimalBits;
	log("Int constructor called.");
	return ;
}

/* --------------------------------- FLOAT CONST --------------------------------- */
static int store_int_part(int x, const int decimal_bits)
{
	int new_bits;

	if (parser(x))
		return (0);
	new_bits = x << decimal_bits; 
	return(new_bits);
}

int power_to(const int base, const int exponent)
{
	int res;

	if (!exponent)
		return (1);
	res = base;
	for(int i = 0; i < exponent - 1; i++)
		res *= base;
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

static int get_dec_part(float fl, int integer_part, const int decimal_bits)
{
	int		decimal_part;
	int		precision;
	float	decimal_only;
	float	int_aspect;
	
	precision = count_mantissa(fl);
	std::cout << precision << std::endl;
	precision = 3;
	decimal_only = (fl - integer_part);
	int_aspect = decimal_only * power_to(10, precision);
	decimal_part = roundf(int_aspect);
	return (decimal_part);
}

Fixed::Fixed(const float fl)
	: _value(0)
{
	int integer_part;
	int decimal_part;

	integer_part = (int) fl;
	this->_value = store_int_part(integer_part, Fixed::_decimalBits);
	decimal_part = get_dec_part(fl, integer_part, Fixed::_decimalBits);
	
	if (parser2(decimal_part))
		return ;
	this->_value = (this->_value) | decimal_part;
	log("Float constructor called.");
	return ;
}

/* --------------------------------- OPERATOR OVERLOAD --------------------------------- */
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

/* --------------------------------- BASE CLASS DEFINITION --------------------------------- */

Fixed::Fixed()
	: _value(0)
{
	log("Default constructor called.");
	return ;
}

Fixed::~Fixed()
{
	log("Destructor called.");
	return ;
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

//COPY CONSTRUCTOR.  THE NAME IS KEY. copy as in, creates a copy, a second object with same values.
//Class SOURCE and the new one just created are NOT the same.
//they dont have the same adress.
//notice how = operator is being used, therefore only contents are copied.
Fixed::Fixed(Fixed const &src)
{
	log("Copy constructor called.");
	*this = src; //this is actually the operator overload of = function being used
	//equivalent to
	//this->operator=(src);
	return ;
}