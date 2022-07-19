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
	: Form("defaultShrubbery", 145, 137), _target("default target")
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
	(void)rhs;
/* 	if (this != &rhs)
	{
		this->_signed = rhs.getStatus();
	} */
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getStatus())
	{
		log("Form is not signed, cannot be executed.");
		return ;
	}
	if (this->execute_check(executor))
	{
		this->form_action();
		log("Shrubbery form executed.");
	}
	else
		throw GradeTooLowException();
}

bool	ShrubberyCreationForm::execute_check(Bureaucrat const & executor) const
{
	int x = executor.getGrade();

	if (x <= this->getExe())
		return (true);
	return (false);
}

void	ShrubberyCreationForm::form_action() const
{
	std::ofstream out_file_object;
	std::string aux("_shrubbery");
	std::string file_name(this->_target + aux);
	std::string tree(TREE);

	out_file_object.open(file_name.c_str(), std::ofstream::out);
	if (!out_file_object.is_open())
	{
		std::cout << "Error on file output" << std::endl;
		throw GradeTooLowException();
	}
	out_file_object << tree << std::endl;

}
