/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Caster.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/09 00:30:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Caster.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Caster	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Caster::Caster()
	: flag(0), _name("Default"), _x(0), _nb(0)
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Caster::Caster(std::string const & instance_name)
	: flag(0), _name(instance_name), _x(0), _nb(0)
{
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Caster::~Caster()
{
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Caster::Caster(Caster const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Caster & Caster::operator=(Caster const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_x	= rhs.getX();
		this->_nb	= rhs.getNb();
	}
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Caster::getName() const
{
	return (this->_name);
}

void Caster::setName(std::string const &name)
{ 
	this->_name = name;
}

char const & Caster::getX() const
{
	return (this->_x);
}

void Caster::setX(char const &x)
{ 
	this->_x = x;
}
double const & Caster::getNb() const
{
	return (this->_nb);
}

void Caster::setNb(double const &nb)
{ 
	this->_nb = nb;
}
/* --------------------------------- METHODS --------------------------------- */
void Caster::InputtoDouble()
{
	try
	{
		_nb = std::stod(getName(), 0);
	}
	catch(const std::exception& e)
	{
		flag++;
		_x = 0;
	}
	if (_nb != _nb)
		flag--;
}


void	Caster::InputtoChar()
{
	char z;
	std::string name(getName());

	if (name.size() == 1 && name[0] != '0')
	{
		z = name[0];
		if (MIN_CHAR <= z && z <= MAX_CHAR )
			_x = z;
		else
			_x = 0;
	}
	if (!_x)
		InputtoDouble();
}
/* --------------------------------- Display --------------------------------- */


void	Caster::displayChar() const
{
	char	x;

	std::cout << "char: ";
	x = getX();
	if (x)
		std::cout << "'" << x << "'";
	else if (MIN_CHAR <= x && x <= MAX_CHAR)
		std::cout << "Non displayable.";
	else if (static_cast<int>(_nb))
	{
		x = static_cast<int>(_nb);
		if (MIN_CHAR <= x && x <= MAX_CHAR )
			std::cout << "'" << x << "'";
		else
			std::cout << "Impossible.";
	}
	else
	{
		if (getName()[0] == '0')
			std::cout << "Non displayable.";
		else
			std::cout << "Impossible.";
	}
	std::cout << std::endl;
}

void	Caster::displayInt() const
{
	char	x;
	double	db;

	std::cout << "int: ";
	x = getX();
	db = getNb();
	if (x)
		std::cout << static_cast<int>(x);
	else if (flag)
		std::cout << "Impossible.";
	else
	{
		if (std::numeric_limits<int>::min() < _nb && _nb < std::numeric_limits<int>::max())
			std::cout << static_cast<int>(db);
		else
			std::cout << "Beyond limits.";
	}
	std::cout << std::endl;
}

static int is_inf(std::string const &str)
{
	if (str[0] == '+' || str[0] == '-' || str[0] == 'i')
		return (1);
	return (0);
}

static void solve_float(double db, std::string const & str)
{
	if (!db)
		std::cout << "0.0f";
	else if (std::numeric_limits<float>::min() < db && db < std::numeric_limits<float>::max())
	{
		std::cout << static_cast<float>(db);
		if (static_cast<long>(db) == static_cast<float>(db))
			std::cout << ".0";
		std::cout << "f";
	}
	else
	{
		if (is_inf(str))
			std::cout << str << "f";
		else
			std::cout << "Beyond limits.";	
	}
}

void	Caster::displayFloat() const
{
	char	x;
	double	db;

	std::cout << "float: ";
	x = getX();
	db = getNb();
	if (x)
		std::cout << static_cast<float>(x) << ".0f";
	else if (flag > 0)
		std::cout << "Impossible.";
	else if (flag < 0)
		std::cout << getName() << "f";
	else
		solve_float(db, getName());
	std::cout << std::endl;
}

void	Caster::displayDouble() const
{
	char	x;
	double	db;

	std::cout << "double: ";
	x = getX();
	db = getNb();
	if (x)
		std::cout << static_cast<double>(x) << ".0";
	else if (flag > 0)
		std::cout << "Impossible.";
	else if (flag < 0)
		std::cout << getName();
	else
	{
		if (!db)
			std::cout << "0.0";
		else if (std::numeric_limits<double>::min() < _nb && _nb < std::numeric_limits<double>::max())
		{
			std::cout << db;
			if (static_cast<int>(db) == db)
				std::cout << ".0";
		}
		else
			std::cout << getName();
	}
	std::cout << std::endl;
}

void	Caster::displayAll() const
{
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}
