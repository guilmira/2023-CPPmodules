/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:15:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/17 20:07:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_decimalBits = DECIMAL_BIT_NBR;

static void log(std::string const &str)
{
	std::cout << str << std::endl;
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
//scale (number of decimal bits) = 8		BFP		0000 0000  -  0000 0000  -  0000 0000 . 0000 0000
//2^0			=		  0000 0001		= 1
//1 << scale	=	0001  0000 0000		= 256
//2^8			=	0001  0000 0000		= 256
//therefore 		2^scale = 1<<scale
//2.5 * 1<<scale=   0010  1000 0000		= 640   Tenemos el FBP perfecto, ya que ese bit en la octava posicion, representa 2^-1 = 0.5
static int float_to_FBP(const float fl, int decimal_bits)
{
	int		fixed_point_value;
	float	offset;

	offset = (float) (1 << decimal_bits);
	fixed_point_value = (int) roundf(fl * offset);
	return (fixed_point_value);
}

Fixed::Fixed(const float fl)
	: _value(0)
{
	int	fixed_point_value;
	
	if (parser((int) fl))
		return ;
	fixed_point_value = float_to_FBP(fl, Fixed::_decimalBits);
	this->_value = fixed_point_value;
	log("Float constructor called.");
	return ;
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

Fixed::Fixed(Fixed const &src)
{
	log("Copy constructor called.");
	*this = src;
	return ;
}

/* --------------------------------- OVERLOAD OUTPUT-STREAM --------------------------------- */
int		Fixed::toInt(void) const
{
	int	decimal_int;

	decimal_int = this->_value >> Fixed::_decimalBits;
	return (decimal_int);
}

//scale (number of decimal bits) = 8		BFP		0000 0000  -  0000 0000  -  0000 0000 . 0000 0000
//2^0			=		  0000 0001		= 1
//1 << scale	=	0001  0000 0000		= 256
//1.5			=	0001  1000 0000		= 384
//384 / 256		= 	1.5
//therefore 	fixed_binary(384) / 1<<scale = actual float number
float	Fixed::toFloat(void) const
{
	float	float_representation;
	float	binary_fixed_nbr;

	binary_fixed_nbr = ( (float) this->getRawBits() );
	float_representation = binary_fixed_nbr / ((float) (1 << Fixed::_decimalBits));
	return (float_representation);
}

std::ostream & operator<<(std::ostream &stream, Fixed const &fixedClass)
{
	std::cout << fixedClass.toFloat();
	return (stream);
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
/* --------------------------------- COMPARITION OPERATORS --------------------------------- */
int Fixed::operator>(Fixed const &rhs) const
{
	return ((this->getRawBits() > rhs.getRawBits()));
}

int Fixed::operator>=(Fixed const &rhs) const
{
	return ((this->getRawBits() >= rhs.getRawBits()));
}

int Fixed::operator<(Fixed const &rhs) const
{
	return ((this->getRawBits() < rhs.getRawBits()));
}

int Fixed::operator<=(Fixed const &rhs) const
{
	return ((this->getRawBits() <= rhs.getRawBits()));
}

int Fixed::operator==(Fixed const &rhs) const
{
	return ((this->getRawBits() == rhs.getRawBits()));
}

int Fixed::operator!=(Fixed const &rhs) const
{
	return ((this->getRawBits() != rhs.getRawBits()));
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	Fixed object_sum;

	object_sum.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (object_sum);
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	Fixed result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits()); 
	return (result);
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed result;
	float result_float;
	int	fixed_point_value;

	result_float = (this->toFloat()) * (rhs.toFloat());
	fixed_point_value = float_to_FBP(result_float, Fixed::_decimalBits);
	result.setRawBits(fixed_point_value);
	return (result);
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed result;
	float result_float;
	int	fixed_point_value;

	result_float = (this->toFloat()) / (rhs.toFloat());
	fixed_point_value = float_to_FBP(result_float, Fixed::_decimalBits);
	result.setRawBits(fixed_point_value);
	return (result);
}

/* --------------------------------- Incrementation --------------------------------- */

Fixed & Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

//exactly the same as ++i, but the return has to be a COPY of the previous state.
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this); //copy constructor used to replicate a temporal class.

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed & Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

/* --------------------------------- STATIC FUNCTIONS --------------------------------- */
Fixed & min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed const & Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed & max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed const & Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return (lhs);
	else
		return (rhs);
}
