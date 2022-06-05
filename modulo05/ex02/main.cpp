/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
	std::cout << "----------------------------------------------" << std::endl;
	
	try
	{
		Bureaucrat	fersea("Lady fersea", 2);
		Bureaucrat	apprentice("Nameless apprentice", 137);

		ShrubberyCreationForm f1(TARGET_NAME);
		RobotomyRequestForm f2("Marvin");
		PresidentialPardonForm f3("Marvin");

		std::cout << "----------------------------------------------" << std::endl;
		f1.beSigned(apprentice);
		f1.beSigned(fersea);
		f1.execute(apprentice);
		f1.execute(fersea);
		std::cout << "----------------------------------------------" << std::endl;
		fersea.signForm(f2);
		f2.beSigned(fersea);
		f2.execute(fersea);
		std::cout << "----------------------------------------------" << std::endl;
		apprentice.signForm(f3);
		fersea.signForm(f3);
		f3.execute(fersea);
		std::cout << "----------------------------------------------" << std::endl;


	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------------------------------------------" << std::endl;
	}

	return (0);
}