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
	{
		return (iterator->second);
	}
	else
		return (result);
}

static std::string		getDate(std::string const &line)
{
	std::string		date;
	size_t			position;

	date.clear();
	position = line.find_first_of('|');
	if (position == std::string::npos || !line[position + 1] || !position)
		return date;
	if (line[position - 1] != ' ' || line[position + 1] != ' ' )
		return date;
	try
	{
		std::stod(line.substr(position + 1));
	}
	catch(const std::exception& e)
	{
		return date;
	}
	date = line.substr(0, position);
	trimSpaces(date);
	return date;
}

void			BitcoinExchange::outputResult(std::string const & file)
{
	double			exchangeRate;
	std::string		line;
	std::ifstream	_file;
	mapIter 		it;
	std::string		date;

	_file.open(file, std::ifstream::in);
	exchangeRate = 1;
	while (std::getline(_file, line))
	{
		date = getDate(line);
		if (date.empty())
			continue;
		it = this->_fileData.find(date);
		exchangeRate = findExchangeRate(it->first);
		if (parserDate(it->first))
			std::cout << "Error: bad input " << " => " << it->first << std::endl;
		else if	(it->second < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (parserNumber(exchangeRate, it->second))
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << it->first << " => " << exchangeRate << " = " << ( it->second * exchangeRate ) << std::endl;

	}
	_file.close();

}


