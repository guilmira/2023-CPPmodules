/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm()
	: Form("default  Presidential", 25, 5), _target("default target")
{
	log("Form constructed.");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("default Presidential", 25, 5), _target(target)
{
	this->ft_throw(this->getSign());
	this->ft_throw(this->getExe());
	log("PresidentialPardonForm overload constructed.");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	log("PresidentialPardonForm destructed.");
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	: Form("default Presidential", 25, 5), _target(src.getTarget())
{

	*this = src;
	log("PresidentialPardonForm copy constructed.");
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	log("PresidentialPardonForm assigned.");
	if (this != &rhs)
	{
		this->_signed = rhs.getStatus();
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}


/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getStatus())
	{
		log("Form is not signed, cannot be executed.");
		return ;
	}
	if (this->execute_check(executor))
		this->form_action();
	else
		throw GradeTooLowException();
}

bool	PresidentialPardonForm::execute_check(Bureaucrat const & executor) const
{
	int x = executor.getGrade();

	if (x <= this->getExe())
		return (true);
	return (false);
}


void	PresidentialPardonForm::form_action() const
{
	std::cout << this->_target << " has been perdoned by Zafod Beeblebrox.\n";
}
