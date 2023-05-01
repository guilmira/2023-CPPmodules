/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 22:18:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Span::Span()
	: _v(1, 0), _size(1), _counter(0)
{
	ilog("Constructed⚪");
	return ;
}

Span::Span(unsigned int N)
	: _v(N, 0), _size(N), _counter(0)
{
	ilog("Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
Span::~Span()
{
	ilog("-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */

/* Usually i do not init in the copy constructor, and instead call assignation by means of *this = src; But in this case is abit more efficient like that and plus i want to ilustrate how the assignation operator = is overloaded for the class vector, making things really easy */
Span::Span(Span const &src)
	: _v(src.getVector())
{
	ilog("Copy constructed");
	return ;
}
/* Easy assignation by using the overload of the class/template vector. */
Span & Span::operator=(Span const &rhs)
{
	ilog("[=] Assignation operator called");
	if (this != &rhs)
	{
		this->_v = rhs.getVector();
	}
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::vector<int> const &	Span::getVector() const
{
	return (this->_v);
}

void						Span::setVector(std::vector<int> const &v)
{ 
	this->_v = v;
}

unsigned int				Span::getSize() const
{
	return(this->_size);
}
void						Span::setSize(unsigned int size)
{
	this->_size = size;
}

unsigned int				Span::getCounter() const
{
	return(this->_counter);
}

void						Span::setCounter(unsigned int counter)
{
	this->_counter = counter;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void Span::ilog(const std::string & msg) const
{
	
	std::cout << "[Class]Span " << "	|	" << msg << std::endl;
}

/* printers made with [] acess and with iterators just to practice. I know what im doing */
void						Span::printSpan() const
{
	std::cout << "Span is: 			 ";
	for (unsigned int i = 0; i < getSize(); i++)
		std::cout << _v[i] << "  "; 
	std::cout << std::endl;
}

void						Span::printVector() const
{
	std::cout << "Vector is: 			 ";
	for (std::vector<int>::const_iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << "  "; 
	std::cout << std::endl;
}

/* Complexity of algorithm: O(n)
Complexity of insert for a vector: O(n) 
Complexity of n^2 */
static void smart_insert(std::vector<int> &v, int value, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (value > v[i])
		{
			v.insert(v.begin() + i, value);
			return ;
		}
	}
	v[size - 1] = value;
}

/* I do not use the function insert, cause that would enlarge the vector (is not a replace afterall, its an insert) */
void	Span::addNumber(int value)
{
	if (getCounter() >= getSize())
		throw ( Span::SpanException() );
	else
	{
		smart_insert(const_cast<std::vector<int> &>(getVector()), value, getSize());
		_counter++;
	}
}

/*  result = v[0] bigger number that i ll have, that simple */
int	Span::shortestSpan()
{

	std::vector<int> v(getVector());
	int difference;
	int result;

	if (getSize() < 1)
		throw (Span::SpanException());
	result = v[0];
	difference = 0;
	for (unsigned int i = 0; i < getCounter() - 1; i++)
	{
		difference = v[i] - v[i + 1];
		if (difference < result)
			result = difference;
	}
	return (result);
}

/* -1 cause if i have two values, 42 and 2
i want to access vector[1] and counter is = 2; */
int	Span::longestSpan()
{
	if (getSize() < 1)
		throw (Span::SpanException());
	else
		return (getVector()[0] - getVector()[getCounter() - 1]);
}

/* Random number by rand. Divided by the range, i get a number from
0 to range. and now + min and all good.
500, 1000
6million / 500 el resto es un numero entre 0 y 500. */
static int generate(int min, int max)
{
	int random;

	random = rand() % (max - min) + min;
	return (random);
}

void		Span::fillSpan(int min, int max, unsigned int n)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++)
		addNumber(generate(min, max));
}
