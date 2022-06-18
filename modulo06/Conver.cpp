/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conver.cpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conver.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

Conver::Conver()
	: _arg("default")
{
	;
}

Conver::Conver(std::string str)
	: _arg(str)
{
	;
}

Conver::~Conver()
{
	;
}

Conver::Conver(Conver const &src)
{

	*this = src;
	log("Conver copy constructed.");
}

Conver & Conver::operator=(Conver const &rhs)
{
	log("Conver assigned.");
	if (this != &rhs)
	{
		this->_arg = rhs.getArg();
	}
	return (*this);
}

std::string Conver::getArg() const
{
	return (this->_arg);
}


void	Conver::display() const
{
	this->conChar();
	this->conInt();
	this->conFloat();
	this->conDouble();
}

void Conver::conChar() const
{
	int i;
	std::string str(this->_arg);
	char z;

	if (str.length() == 1)
	{
		if (!isdigit(str[0]))
			std::cout << "char:		" << "'" << str[0] << "'" << std::endl;
		else
			std::cout << "char:		" << "Non displayable" << std::endl;
	}
	else
	{
		try
		{
			i = std::stoi(str);
			z = static_cast<char>(i);
			if (std::isprint(z) && i <= 127)
				std::cout << "char:		" << "'" << z << "'" << std::endl;
			else
				std::cout << "char:		" << "Non displayable" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "char:		" << "Invalid char argument" << '\n';
		}
		
	}
}

void Conver::conInt() const
{
	int i;

	try
	{
		i = std::stoi(this->getArg());
		std::cout << "int:		" << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int:		" << "Invalid int argument\n";
	}
}

void Conver::conFloat() const
{
	float fl;

	try
	{
		fl = std::stof(this->getArg());
		std::cout << "float:		" <<  fl ;
		if (fl - static_cast<int>(fl) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "float:		" << "Invalid float argument\n";
	}
}

void Conver::conDouble() const
{
	double db;

	try
	{
		db = std::stod(this->getArg());
		std::cout << "double:		" << db;
		if (db - static_cast<int>(db) == 0)
			std::cout << ".0";
		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << "double:		" << "Invalid double argument\n";
	}
}

