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

#include "Span.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
Span::Span()
{
	ilog("Constructed⚪");
	return ;
}

Span::Span(unsigned int N)
	: _v(N, 0)
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
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void Span::ilog(const std::string & msg) const
{
	
	std::cout << "[Class]Span " << "	|	" << msg << std::endl;
}

void	Span::addNumber(int i)
{
	_v.push_back(i);
}

int	Span::shortestSpan()
{
	return 1;
}

int	Span::longestSpan()
{
	return 10000;
}