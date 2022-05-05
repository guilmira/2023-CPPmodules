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
static int	get_decimal(const int x)
{
	int dec;
	int modifier;

	modifier = 0;
	for (int i = 0; i < DECIMAL_BIT_NBR; i++)
	{
		if (i != 0)
			modifier = modifier << 1;
		modifier = 1 | modifier;
	}
 	dec = x & modifier;
	return (dec);
}

static int	get_integer(const int x)
{
	int integer;
	int offset;

	offset = DECIMAL_BIT_NBR;
 	integer = x >> offset;
	return (integer);
}

std::ostream & operator<<(std::ostream &stream, Fixed const &fixedClass)
{
	int integer_part;
	int decimal_part;
	
	integer_part = get_integer(fixedClass.getRawBits());
	decimal_part = get_decimal(fixedClass.getRawBits());
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
	this->_value = i << 8;
	log("Int constructor called.");
	return ;
}

/* --------------------------------- FLOAT CONST --------------------------------- */
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


static int store_int_part(int x)
{
	int new_bits;

	if (parser(x))
		return (0);
	new_bits = x << 8; 
	return(new_bits);
}

Fixed::Fixed(const float fl)
	: _value(0)
{
	int integer_part;
	int decimal_part;

	integer_part = (int) fl;
	this->_value = store_int_part(integer_part);
	//roundf ALLOWED FUNCTION

	int precision ;
	/* precision = count_mantissa(fl);
	std::cout << precision << std::endl; */
	precision = 3;
	decimal_part = (fl - integer_part) * power_to(10, precision);
	std::cout << "here " << (fl - integer_part) << std::endl;
	std::cout << "here " << decimal_part << std::endl;

	

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
	log("getRawBits member fuction called.");
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	log("setRawBits member fuction called.");
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