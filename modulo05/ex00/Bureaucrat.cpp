/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/19 12:19:17 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream & operator<<(std::ostream &stream, Bureaucrat const &rhs)
{
	stream << "Bureaucrat with parameters: ";
	stream << rhs.getName();
	stream << " and ";
	stream << rhs.getGrade();
	return (stream);
}

void Bureaucrat::ft_throw()
{
	int grade;
	
	grade = this->getGrade();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
	log("Bureaucrat constructed.");
}

Bureaucrat::Bureaucrat(std::string str)
	: _name(str), _grade(150)
{
	log("Bureaucrat overload constructed 1 .");
}

Bureaucrat::Bureaucrat(std::string str, int grade)
	: _name(str), _grade(grade)
{
	this->ft_throw();
	log("Bureaucrat overload constructed 2.");
}

Bureaucrat::~Bureaucrat()
{
	log("Bureaucrat destructed.");
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
	: _name(getName())
{
	*this = src;
	log("Bureaucrat copy constructed.");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	log("Bureaucrat assigned.");
	if (this != &rhs)
		this->setGrade(rhs.getGrade());
	return (*this);
}

Bureaucrat & Bureaucrat::operator++()
{
	this->_grade = this->getGrade() + 1;
	this->ft_throw();
	return (*this);
}

Bureaucrat & Bureaucrat::operator--()
{
	this->_grade = this->getGrade() - 1;
	this->ft_throw();
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat aux = Bureaucrat(*this);

	this->_grade = this->getGrade() + 1;
	this->ft_throw();
	return (aux);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat aux = Bureaucrat(*this);

	this->_grade = this->getGrade() - 1;
	this->ft_throw();
	return (aux);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int x)
{
	this->_grade = x;
	this->ft_throw();
}


/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */


/* Usually, a std::exception, which is a class, is the object that is thrown. 
It is created on the ---throw: throw std::exception--- , and then caught with a catch
Now, we are throwing the same, an object, that simply inherithed fromt std::exception, so its basically the same, plus an error message
So if before i had:
---			throw std::exception;
---			throw namespace::NAME;
Now:
---			throw Bureaucrat::GradeTooHighException; */
Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "--HIGH constructed and ready to be catched.--\n";
}

/* Explanation of throw() at the end of the function. It means that by no means, this function called what is gonna throw anything.
If it would be throw(int x), it would mean that it is gonna throw an int.
The important part, is that what i am gonna throw, is the clase GradeTooHigh, so i know the function just has to print "what" has failed, and definetly not throw anything. */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception thrown.\n"); 
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{ 
	std::cout << "--LOW constructed and ready to be catched.--\n"; 
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception thrown.\n"); 
}