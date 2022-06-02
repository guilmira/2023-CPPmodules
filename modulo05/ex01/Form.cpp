/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


std::ostream & operator<<(std::ostream &stream, Form const &rhs)
{
	stream << "Form: ";
	stream << rhs.getName();
	stream << " is ";
	if (rhs.getSigned())
		stream << "signed." << std::endl;
	else
		stream << "not signed." << std::endl;
	stream << "Grades required: ";
	stream << rhs.getSign();
	stream << " and ";
	stream << rhs.getExe() << std::endl;
	return (stream);
}

void Form::ft_throw()
{
	int grade;
	
	grade = this->getGrade();
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

Form::Form()
	: _name("default"), _grade(150)
{
	log("Form constructed.");
}

Form::Form(std::string str)
	: _name(str), _grade(150)
{
	log("Form overload constructed 1 .");
}

Form::Form(std::string str, int grade)
	: _name(str), _grade(grade)
{
	this->ft_throw();
	log("Form overload constructed 2.");
}

Form::~Form()
{
	log("Form destructed.");
}

Form::Form(Form const &src)
{

	*this = src;
	log("Form copy constructed.");
}

Form & Form::operator=(Form const &rhs)
{
	log("Form assigned.");
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->setGrade(rhs.getGrade());
	}
	return (*this);
}

Form & Form::operator++()
{
	this->_grade = this->getGrade() + 1;
	this->ft_throw();
	return (*this);
}

Form & Form::operator--()
{
	this->_grade = this->getGrade() - 1;
	this->ft_throw();
	return (*this);
}

Form Form::operator++(int)
{
	Form aux = Form(*this);

	this->_grade = this->getGrade() + 1;
	this->ft_throw();
	return (aux);
}

Form Form::operator--(int)
{
	Form aux = Form(*this);

	this->_grade = this->getGrade() - 1;
	this->ft_throw();
	return (aux);
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSign() const
{
	return (this->_grade_to_sign);
}

int Form::getExe() const
{
	return (this->_grade_to_exe);
}


void Form::setGrade(int x)
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
---			throw Form::GradeTooHighException; */
Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "--HIGH constructed and ready to be catched.--\n";
}

/* Explanation of throw() at the end of the function. It means that by no means, this function called what is gonna throw anything.
If it would be throw(int x), it would mean that it is gonna throw an int.
The important part, is that what i am gonna throw, is the clase GradeTooHigh, so i know the function just has to print "what" has failed, and definetly not throw anything. */
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception thrown.\n"); 
}

Form::GradeTooLowException::GradeTooLowException()
{ 
	std::cout << "--LOW constructed and ready to be catched.--\n"; 
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception thrown.\n"); 
}