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
	std::cout << "char:		" << this->conChar() << std::endl;
	std::cout << "int:		" << this->conInt() << std::endl;
	std::cout << "float:	" << this->conFloat() << std::endl;
	std::cout << "double:	" << this->conDouble() << std::endl;
}

char Conver::conChar() const
{
	int i;
	char z;

	z = 'x';
	i = this->conInt();
	if (i > 0)
		return(static_cast<char>(i));
	return (z);
}

int Conver::conInt() const
{
	int i;

	try
	{
		i = std::stoi(this->getArg());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ":Invalid argument\n";
	}

	return (i);
}

float Conver::conFloat() const
{
	int i;
	float fl;

	i = conInt();

	fl = static_cast<float>(i);

	return (fl);
}

double Conver::conDouble() const
{
	int i;
	double db;

	i = conInt();

	db = static_cast<double>(i);

	return (db);
}

