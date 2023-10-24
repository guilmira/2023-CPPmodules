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
		_after.push_back(std::stoi(str));
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

void	PmergeMe::displayBefore()
{
	std::cout << "Before:";
	for (std::vector<int>::iterator it = _before.begin(); it != _before.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	/* std::vector<int> v;
	 std::sort(v.begin(), v.end());
	for (std::vector<int>::iterator it = v.begin(); it != v.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl; */


	return ;
}

void	PmergeMe::displayAfter()
{
	std::cout << "After:";
	std::cout << std::endl;
	for (std::vector<int>::iterator it = _after.begin(); it != _after.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	return ;
}

void	PmergeMe::displayEnd()
{
	double		time1 = 0;
	double		time2 = 0;

	std::cout << "Time to process a range of " << _totalElements << " elements with std::vector : " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << _totalElements << " elements with std::list : " << time2 << " us" << std::endl;
	return ;
}


bool isEven(myVector vector)
{
	if (vector.size() % 2 == 0)
		return true;
	else
		return false;
}

void	PmergeMe::printVec(myVector const & vector) const
{
	for (myVector::const_iterator it = vector.begin(); it != vector.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	printVec(myVector const & vector)
{
	for (myVector::const_iterator it = vector.begin(); it != vector.end() ; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void splitVector(myVector & first, myVector & second, myVector const & vector) 
{
	int medianPosition;

	medianPosition = ((int) vector.size() / 2);
	first = myVector(vector.begin(), vector.begin() + medianPosition);
	second = myVector(vector.begin() + medianPosition, vector.end());
}

myVector mergeInsertion(myVector first, myVector second)
{
	int				minValueFirst;
	int				minValueSecond;
	size_t totalSize = first.size() + second.size();
	myVector		result(totalSize, -1);
	
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

myVector mergeRecursion(myVector vector)
{
	myVector first;
	myVector second;
	myVector merged;

	if (vector.size() == 1)
		return myVector(vector);
	else
	{
		splitVector(first, second, vector);
		first = mergeRecursion(first);
		second = mergeRecursion(second);
		merged = mergeInsertion(first, second);
		return (merged);
	}
}

void	PmergeMe::mergeInsertionSort()
{
	std::vector<int> firstHalf;
	std::vector<int> secondHalf;
	std::vector<int> result;

	splitVector(firstHalf, secondHalf, _before);
	_after = mergeRecursion(_before);
}
