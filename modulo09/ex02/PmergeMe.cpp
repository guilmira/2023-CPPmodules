/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
PmergeMe::PmergeMe()
	: _line("Default")
{
	ilog(getLine(), "Constructed⚪");
	return ;
}

static bool	parserCheck(std::string const &line)
{
	size_t	position;

	position = line.find_first_of(' ');
	if (position != std::string::npos)
	{
		std::cout << "Error: Spaces not allowed" << std::endl;
		return false;
	}
	position = line.find_first_of('-');
	if (position != std::string::npos)
	{
		std::cout << "Error: Natural numbers only" << std::endl;
		return false;
	}
	try
	{
		std::stoi(line);
	}
	catch(const std::exception& e)
	{
		std::cout << "stoi failed" << std::endl;
	}
	
	return true;
}

PmergeMe::PmergeMe(char **argv, std::string const & line, int totalElements)
	: _line(line), _totalElements(totalElements)
{
	std::string			str;

	for (size_t i = 1; i < static_cast<size_t>(totalElements) + 1; i++)
	{
		str = argv[i];
		if (!parserCheck(str))
			throw std::exception();
		_before.push_back(std::stoi(str));
		_beforeDeque.push_back(std::stoi(str));
	}
	ilog(getLine(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
PmergeMe::~PmergeMe()
{
	
	ilog(getLine(), "-Destroyed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;

	(void) _totalElements;
	ilog(getLine(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
PmergeMe & PmergeMe::operator=(PmergeMe const &rhs)
{
	ilog(getLine(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setLine(rhs.getLine());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & PmergeMe::getLine() const
{
	return (this->_line);
}

void PmergeMe::setLine(std::string const &line)
{ 
	this->_line = line;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void PmergeMe::ilog(const std::string & line, const std::string & msg) const
{
	return ;
	std::cout << "[Class]PmergeMe	- [Instance]" << line << "	|	"\
	<< msg << std::endl;
}



template <typename T>
static void splitContainer(T & first, T & second, T const & container) 
{
	int medianPosition;

	medianPosition = ((int) container.size() / 2);
	first = T(container.begin(), container.begin() + medianPosition);
	second = T(container.begin() + medianPosition, container.end());
}

static myVector mergeInsertion(myVector first, myVector second)
{
	int				minValueFirst;
	int				minValueSecond;
	size_t totalSize = first.size() + second.size();
	myVector			result(totalSize, -1);
	
	int 			firstCounter = 0;
	int 			secondCounter = 0;
	int 			minValue;

	minValue = -1;
	for (myVector::iterator iterResult = result.begin(); iterResult != result.end() ; iterResult++)
	{
		for (myVector::const_iterator iterFirst = first.begin() + firstCounter; iterFirst != first.end() ; iterFirst++)
		{
			if (minValue < 0)
				minValue = *iterFirst;
			if (*iterFirst <= minValue)
			{
				minValue = *iterFirst;
				minValueFirst = minValue;
			}
		}
		minValueSecond = -1;
		for (myVector::const_iterator iterSec = second.begin() + secondCounter; iterSec != second.end() ; iterSec++)
		{
			if (minValue < 0)
				minValue = *iterSec;
			if (*iterSec <= minValue)
			{
				minValue = *iterSec;
				minValueSecond = minValue;
			}
		}
		if (minValueSecond > 0)
		{
			*iterResult = minValueSecond;
			secondCounter++;
		}
		else
		{
			*iterResult = minValueFirst;
			firstCounter++;
		}
		minValue = -1;
	}
	return result;
}

myVector PmergeMe::sortMI(myVector vector)
{
	myVector first;
	myVector second;
	myVector merged;

	if (vector.size() == 1)
		return myVector(vector);
	else
	{
		splitContainer(first, second, vector);
		first = sortMI(first);
		second = sortMI(second);
		merged = mergeInsertion(first, second);
		return (merged);
	}
}


static myDeque DequeMergeInsertion(myDeque first, myDeque second)
{
	int				minValueFirst;
	int				minValueSecond;
	size_t totalSize = first.size() + second.size();
	myDeque		result(totalSize, -1);
	
	int 			firstCounter = 0;
	int 			secondCounter = 0;
	int 			minValue;

	minValue = -1;
	for (myDeque::iterator iterResult = result.begin(); iterResult != result.end() ; iterResult++)
	{
		for (myDeque::const_iterator iterFirst = first.begin() + firstCounter; iterFirst != first.end() ; iterFirst++)
		{
			if (minValue < 0)
				minValue = *iterFirst;
			if (*iterFirst <= minValue)
			{
				minValue = *iterFirst;
				minValueFirst = minValue;
			}
		}
		minValueSecond = -1;
		for (myDeque::const_iterator iterSec = second.begin() + secondCounter; iterSec != second.end() ; iterSec++)
		{
			if (minValue < 0)
				minValue = *iterSec;
			if (*iterSec <= minValue)
			{
				minValue = *iterSec;
				minValueSecond = minValue;
			}
		}
		if (minValueSecond > 0)
		{
			*iterResult = minValueSecond;
			secondCounter++;
		}
		else
		{
			*iterResult = minValueFirst;
			firstCounter++;
		}
		minValue = -1;
	}
	return result;
}

myDeque PmergeMe::DequeSortMI(myDeque vector)
{
	myDeque first;
	myDeque second;
	myDeque merged;

	if (vector.size() == 1)
		return myDeque(vector);
	else
	{
		splitContainer(first, second, vector);
		first = DequeSortMI(first);
		second = DequeSortMI(second);
		merged = DequeMergeInsertion(first, second);
		return (merged);
	}
}
