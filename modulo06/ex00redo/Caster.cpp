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

#define MIN_CHAR ' '
#define MAX_CHAR '~'

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Caster	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Caster::Caster()
	: _name("Default"), _x(0), _nb(0)
{
	ilog(getName(), "Constructed⚪");
	return ;
}

Caster::Caster(std::string const & instance_name)
	: _name(instance_name), _x(0), _nb(0)
{
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Caster::~Caster()
{
	ilog(getName(), "-Destructed⭕");
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
		flag = 1;
		std::cerr << e.what() << '\n';
		_x = 0;
	}
}


void	Caster::InputtoChar()
{
	char z;
	std::string name(getName());

	if (name.size() == 1)
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

void	Caster::displayChar() const
{
	char	x;

	std::cout << "char: ";
	x = getX();
	if (x)
		std::cout << "'" << x << "'";
	else if (MIN_CHAR <= x && x <= MAX_CHAR )
		std::cout << "Non displayable.";
	else if (static_cast<int>(_nb))
	{
		x = static_cast<int>(_nb);
		if (MIN_CHAR <= x && x <= MAX_CHAR )
			std::cout << "'" << x << "'";
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

void	Caster::displayFloat() const
{
	char	x;
	double	db;

	std::cout << "float: ";
	x = getX();
	db = getNb();
	if (x)
		std::cout << static_cast<float>(x) << ".0f";
	else if (flag)
		std::cout << "Impossible.";
	else
	{
		if (std::numeric_limits<float>::min() < _nb && _nb < std::numeric_limits<float>::max())
			std::cout << static_cast<float>(db);
		else
		{
			std::cout << "Beyond limits." << std::endl;
			return ;
		}
		if (static_cast<int>(db) == static_cast<float>(db))
			std::cout << ".0";
		std::cout << "f";
	}
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
	else if (flag)
		std::cout << "Impossible.";
	else
	{
		if (std::numeric_limits<double>::min() < _nb && _nb < std::numeric_limits<double>::max())
			std::cout << db;
		if (static_cast<int>(db) == db)
			std::cout << ".0";
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

/* esto se puede pero no es necesario, porque todo lo vas a gestionar igual
try
	{
		i = std::stoi(getName());
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	catch(const std::out_of_range & e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
	catch(const std::exception& e)
	{
		std::cout << "⭕OUTPUT⭕" << std::endl;
		std::cerr << e.what() << '\n';
		return (-1);
	} */