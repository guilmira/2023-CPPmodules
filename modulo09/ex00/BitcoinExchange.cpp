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

BitcoinExchange::BitcoinExchange(std::string const & name, std::string const & database)
	: _name(name)
{
	std::ifstream					_database;

	_database.exceptions(std::ifstream::failbit);
	_database.open(database, std::ifstream::in);
	_database.exceptions(std::ifstream::goodbit);
	this->_rates = buildMap(_database, ',');
	_database.close();
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
	{
		this->setName(rhs.getName());
		this->_rates = rhs._rates;
	}
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
	return ;
	std::cout << "[Class]BitcoinExchange	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
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
	double			value;
	size_t			position;
	myMap			newMap;
	
	while (std::getline(file, line))
	{
		position = line.find_first_of(delimiter);
		if (position == std::string::npos || !line[position + 1] || !position)
			continue;
		if (delimiter == '|')
			if (line[position - 1] != ' ' || line[position + 1] != ' ' )
				continue;
		date = line.substr(0, position);
		trimSpaces(date);
		try
		{
			value = std::stod(line.substr(position + 1));
		}
		catch(const std::exception& e)
		{
			continue;
		}
		newMap.insert(std::make_pair(date, value));
	}
	return newMap;
}

void			BitcoinExchange::printRates(myMap m)
{
	for (mapIter it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}

bool			BitcoinExchange::parserDate(std::string const &date)
{
	int		year;
	int		month;
	int 	day;

	try
	{
		year = std::stoi(date.substr(0, 4));	
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	}
	catch (std::exception & e)
	{
		return true;
	}
	if (year < 0 || year > 2023)
		return true;
	if (month < 0 || month > 12)
		return true;
	if (day < 0 || day > 30)
		return true;
	return false;
}

bool			BitcoinExchange::parserNumber(double value, double value2)
{
	if (value2 > 1000)
		return true;
	if (value > std::numeric_limits<float>::max() || \
	value2 > std::numeric_limits<float>::max() )
		return true;
	else if (value * value2 > std::numeric_limits<float>::max())
		return true;
	return false;
}

double			BitcoinExchange::findExchangeRate(std::string const &date)
{
	double		result;
	mapIter		iterator;

	result = 1;
	iterator = this->_rates.find(date);
	if (iterator != _rates.end())
		return (iterator->second);
	iterator = this->_rates.lower_bound(date);
	if (iterator != _rates.end())
	{
		if (iterator != _rates.begin())
			iterator--;
		return (iterator->second);
	}
	iterator = this->_rates.end();
	iterator--;
	return (iterator->second);
}

static bool	getParam(std::string const &line, std::string &date, float &nb)
{
	size_t			position;

	date.clear();
	nb = 0;
	position = line.find_first_of('|');
	if (position == std::string::npos || !line[position + 1] || !position)
		return false;
	if (line[position - 1] != ' ' || line[position + 1] != ' ' )
		return false;
	date = line.substr(0, position);
	trimSpaces(date);
	try
	{
		nb = std::stod(line.substr(position + 1));
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return true;
}

void			BitcoinExchange::outputResult(std::string const & file)
{
	double			exchangeRate;
	std::string		line;
	std::ifstream	_file;
	mapIter 		it;
	std::string		date;
	float			nb;

	_file.open(file, std::ifstream::in);
	exchangeRate = 1;
	while (std::getline(_file, line))
	{
		if (!line.compare(HEADERLINE))
			continue;
		if (!getParam(line, date, nb))
		{
			date = line;
			std::cout << "Error: bad input " << " => " << date << std::endl;
			continue ;
		}
		exchangeRate = findExchangeRate(date);
		if (parserDate(date))
			std::cout << "Error: bad input " << " => " << date << std::endl;
		else if	(nb < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (parserNumber(exchangeRate, nb))
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << date << " => " << nb << " = " << ( nb * exchangeRate ) << std::endl;
	}
	_file.close();

}
