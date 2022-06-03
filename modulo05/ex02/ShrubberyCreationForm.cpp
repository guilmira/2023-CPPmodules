/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("defaultShrubbery", 145, 137)
{
	log("Form constructed.");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("defaultShrubbery", 145, 137), _target(target)
{
	this->ft_throw(this->getSign());
	this->ft_throw(this->getExe());
	log("ShrubberyCreationForm overload constructed.");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	log("ShrubberyCreationForm destructed.");
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: Form("defaultShrubbery", 145, 137), _target(src.getTarget())
{

	*this = src;
	log("ShrubberyCreationForm copy constructed.");
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	log("ShrubberyCreationForm assigned.");
	if (this != &rhs)
	{
		this->_signed = rhs.getStatus();
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	int x = executor.getGrade();
	x = (int) x;
}
