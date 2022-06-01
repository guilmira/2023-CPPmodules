/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


std::ostream & operator<<(std::ostream &stream, Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat with parameters: ";
	std::cout << rhs.getName();
	std::cout << " and ";
	std::cout << rhs.getGrade();
	return (stream);
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
	this->GradeTooHighException();
	this->GradeTooLowException();
	log("Bureaucrat overload constructed 2.");
}

Bureaucrat::~Bureaucrat()
{
	log("Bureaucrat destructed.");
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{

	*this = src;
	log("Bureaucrat copy constructed.");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	log("Bureaucrat assigned.");
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::GradeTooHighException()
{
	if (this->_grade < 1)
		throw std::exception();
	return ;
}

void Bureaucrat::GradeTooLowException()
{
	if (this->_grade > 150)
		throw std::exception();
	return ;
}