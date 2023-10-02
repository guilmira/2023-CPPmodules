/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* CLASS DEFINITION. */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
RPN::RPN()
	: _name("Default")
{
	ilog(getName(), "Constructed⚪");
	return ;
}

static bool			isMathOperand(char z)
{
	if (z == ADDITION)
		return true;
	if (z == SUBSTRACTION)
		return true;
	if (z == MULTIPLICATION)
		return true;
	if (z == DIVISION)
		return true;
	return false;
}

long int	solveOperator(long int first, long int second, char z)
{
	if (z == ADDITION)
		return first + second;

	if (z == SUBSTRACTION)
		return first - second;

	if (z == MULTIPLICATION)
		return first * second;

	if (z == DIVISION)
		return first / second;
	
	return 0;
}


void				RPN::buildStack()
{
	long int					first;
	long int					second;
	long int					result;
	std::stack<long int>		stack;


	for (size_t i = 0; i < this->_line.length(); i++)
	{
		if (isdigit(_line[i]))
			stack.push(std::stol(std::string(&this->_line[i], 1)));
		if (isMathOperand(_line[i]))
		{
			second = stack.top();
			stack.pop();
			first = stack.top();
			stack.pop();
			result = solveOperator(first, second, _line[i]);
			stack.push(result);
		}
	}
	std::cout << stack.top() << std::endl;
}


RPN::RPN(std::string const & name, std::string const & line)
	: _name(name), _line(line)
{
	buildStack();
	ilog(getName(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
RPN::~RPN()
{
	ilog(getName(), "-Destroyed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
RPN::RPN(RPN const &src)
{
	*this = src;
	ilog(getName(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
RPN & RPN::operator=(RPN const &rhs)
{
	ilog(getName(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setName(rhs.getName());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & RPN::getName() const
{
	return (this->_name);
}

void RPN::setName(std::string const &name)
{ 
	this->_name = name;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void RPN::ilog(const std::string & name, const std::string & msg) const
{
	
	std::cout << "[Class]RPN	- [Instance]" << name << "	|	"\
	<< msg << std::endl;
}
