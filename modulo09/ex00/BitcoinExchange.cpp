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

void	BitcoinExchange::buildRates()
{
	std::string		line;
	std::string		date;
	float			value;
	size_t			position;
	
	while (std::getline(this->_database, line))
	{
		position = line.find(',');
		if (position == std::string::npos || !line[position + 1])
			continue;
		date = line.substr(0, position);
		try
		{
			value = std::stof(line.substr(position + 1));
		}
		catch(const std::exception& e)
		{
			continue;
		}
		_rates.insert(std::make_pair(date ,value));
	}
	printRates();
}

BitcoinExchange::BitcoinExchange(std::string const & name, std::string const & database, std::string const & file)
	: _name(name)
{

	_database.exceptions(std::ifstream::failbit);
	_file.exceptions(std::ifstream::failbit);

	_database.open(database, std::ifstream::in);
	_file.open(file, std::ifstream::in);

	_database.exceptions(std::ifstream::goodbit);
	_file.exceptions(std::ifstream::goodbit);

	this->buildRates();
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
BitcoinExchange::~BitcoinExchange()
{
	_database.close();
	_file.close();
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

void			BitcoinExchange::printRates()
{
	for (mapIter it = this->_rates.begin(); it != this->_rates.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}
