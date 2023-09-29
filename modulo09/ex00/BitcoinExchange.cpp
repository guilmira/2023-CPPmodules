/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
BitcoinExchange::BitcoinExchange()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

static void		trimSpaces(std::string &str)
{
	size_t init;
	size_t end;

	init = str.find_first_not_of(' ');
	end = str.find_last_not_of(' ');

	str = str.substr(init, end - init + 1);
}

myMap	BitcoinExchange::buildMap(std::ifstream &file, char delimiter)
{
	std::string		line;
	std::string		date;
	float			value;
	size_t			position;
	myMap			newMap;
	
	while (std::getline(file, line))
	{
		position = line.find(delimiter);
		if (position == std::string::npos || !line[position + 1])
			continue;
		date = line.substr(0, position);
		trimSpaces(date);
		try
		{
			value = std::stof(line.substr(position + 1));
		}
		catch(const std::exception& e)
		{
			continue;
		}
		newMap.insert(std::make_pair(date, value));
	}
	return newMap;
}

BitcoinExchange::BitcoinExchange(std::string const & name, std::string const & database, std::string const & file)
	: _name(name)
{

	std::ifstream					_database;
	std::ifstream					_file;

	_database.exceptions(std::ifstream::failbit);
	_file.exceptions(std::ifstream::failbit);

	_database.open(database, std::ifstream::in);
	_file.open(file, std::ifstream::in);

	_database.exceptions(std::ifstream::goodbit);
	_file.exceptions(std::ifstream::goodbit);

	this->_rates = buildMap(_database, ',');
	this->_fileData = buildMap(_file, '|');

	_database.close();
	_file.close();
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
BitcoinExchange::~BitcoinExchange()
{
	ilog(getName(), "-Destroyed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setName(rhs.getName());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & BitcoinExchange::getName() const
{
	return (this->_name);
}

void BitcoinExchange::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void BitcoinExchange::ilog(const std::string & name, const std::string & msg) const
{
	
	std::cout << "[Class]BitcoinExchange	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}

void			BitcoinExchange::printRates(myMap m)
{
	for (mapIter it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}

void			BitcoinExchange::outputResult()
{
	for (mapIter it = this->_fileData.begin(); it != this->_fileData.end() ; it++)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}

	// std::cout << exchanger._rates["2022-03-25"] << std::endl;
	std::cout << "⭕OUTPUT⭕" << std::endl;
}

