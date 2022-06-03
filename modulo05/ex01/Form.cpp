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
	if (rhs.getStatus())
		stream << "signed." << std::endl;
	else
		stream << "not signed." << std::endl;
	stream << "Grades required: ";
	stream << rhs.getSign();
	stream << " and ";
	stream << rhs.getExe() << std::endl;
	return (stream);
}

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

Form::Form()
	: _name("default"), _signed(0), _grade_to_sign(150), _grade_to_exe(150)
{
	log("Form constructed.");
}

Form::Form(std::string str, int grade_sign, int grade_exe)
	: _name(str), _signed(0), _grade_to_sign(grade_sign), _grade_to_exe(grade_exe)
{
	this->ft_throw(this->getSign());
	this->ft_throw(this->getExe());
	log("Form overload constructed 1 .");
}

Form::~Form()
{
	log("Form destructed.");
}

Form::Form(Form const &src)
{

	*this = src;
	log("Form copy constructed. It dosent do anyhthing.");
}

Form & Form::operator=(Form const &rhs)
{
	log("Form assigned. It dosent do anything because values are const.");
	if (this != &rhs)
	{
		this->_signed = rhs.getStatus();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getStatus() const
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

void Form::beSigned(Bureaucrat const &buro)
{
	if (this->getStatus())
	{
		std::cout << "Form is already signed.\n";
		return ;
	}
	if (buro.getGrade() >= this->getStatus())
	{
		this->_signed = 1;
		//buro.signForm(*this);
	}
	else
	{
		;
		//buro.signForm(*this);
	}

}


/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */

void Form::ft_throw(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "FORM | --HIGH constructed and ready to be catched.--\n";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("FORM | Grade too high exception thrown.\n"); 
}

Form::GradeTooLowException::GradeTooLowException()
{ 
	std::cout << "FORM | --LOW constructed and ready to be catched.--\n"; 
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("FORM | Grade too low exception thrown.\n"); 
}