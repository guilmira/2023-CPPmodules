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
	: _line("Default")
{
	ilog(getLine(), "Constructed⚪");
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

double	solveOperator(double first, double second, char z)
{
	long double result;

	result = 0;
	if (z == ADDITION)
		result = first + second;
	if (z == SUBSTRACTION)
		result = first - second;
	if (z == MULTIPLICATION)
		result = first * second;
	if (z == DIVISION)
		result = first / second;
	return result;
}

void				RPN::buildStack()
{
	double					first;
	double					second;
	double					result;
	std::stack<double>		stack;
	size_t					size = 0;
	bool					flag;

	flag = false;
	for (size_t i = 0; i < this->_line.length(); i++)
	{
		if (_line[i] == '-' && isdigit(_line[i + 1]))
			flag = true;
		if (isdigit(_line[i]))
		{
			for (size_t j = i; this->_line.length(); j++)
			{
				if (!isdigit(_line[j]))
					break ;
				size++;
			}
			result = std::stod(std::string(&this->_line[i], size));
			if (flag)
				stack.push(result * (-1));
			else
				stack.push(result);
			i = i + size;
			size = 0;
			flag = false;
		}
		else if (isMathOperand(_line[i]) && !flag)
		{
			second = stack.top();
			stack.pop();
			first = stack.top();
			stack.pop();
			result = solveOperator(first, second, _line[i]);
			stack.push(result);
			flag = false;
		}
	}
	std::cout << stack.top() << std::endl;
}


RPN::RPN(std::string const & line)
	: _line(line)
{
	buildStack();
	ilog(getLine(), "Overload constructed⚪");
	return ;
}
/* --------------------------------- DESTRUCTOR --------------------------------- */
RPN::~RPN()
{
	ilog(getLine(), "-Destroyed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
RPN::RPN(RPN const &src)
{
	*this = src;
	ilog(getLine(), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
RPN & RPN::operator=(RPN const &rhs)
{
	ilog(getLine(), "[=] Assignation operator called");
	if (this != &rhs)
		this->setLine(rhs.getLine());
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & RPN::getLine() const
{
	return (this->_line);
}

void RPN::setLine(std::string const &line)
{ 
	this->_line = line;
}
/* --------------------------------- METHODS --------------------------------- */
/* ilog = instance log */
void RPN::ilog(const std::string & line, const std::string & msg) const
{
	return ;
	std::cout << "[Class]RPN	- [Instance]" << line << "	|	"\
	<< msg << std::endl;
}
