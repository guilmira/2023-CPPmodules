/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm()
	: Form("default robotomy", 72, 45), _target("default target")
{
	log("Form constructed.");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("defaultrobotomy", 72, 45), _target(target)
{
	this->ft_throw(this->getSign());
	this->ft_throw(this->getExe());
	log("RobotomyRequestForm overload constructed.");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	log("RobotomyRequestForm destructed.");
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: Form("defaultrobotomy", 72, 45), _target(src.getTarget())
{

	*this = src;
	log("RobotomyRequestForm copy constructed.");
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	log("RobotomyRequestForm assigned.");
	if (this != &rhs)
	{
		this->_signed = rhs.getStatus();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}


/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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

bool	RobotomyRequestForm::execute_check(Bureaucrat const & executor) const
{
	int x = executor.getGrade();

	if (x <= this->getExe())
		return (true);
	return (false);
}


void	RobotomyRequestForm::form_action() const
{
	int random;

	log("*drilling noises*");
	srand ( time(NULL) );
	random = rand() % 10 + 1;
	if (random <= 5)
		std::cout << this->_target << " robotimized.\n";
	else
		std::cout << this->_target << " is saved.\n";

}
