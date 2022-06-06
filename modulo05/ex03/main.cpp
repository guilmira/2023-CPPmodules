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
#include "Intern.hpp"


void logg(std::string const &str)
{
	std::cout << str << std::endl;
}

//just an example of syntaxis
typedef void (*new_type_function)(std::string const &str);

int	main(void)
{

	new_type_function variable = &logg;
	variable("test");
	{
	std::cout << "----------------------------------------------" << std::endl;
	
	try
	{
		Bureaucrat	fersea("Lady fersea", 2);
		Bureaucrat	apprentice("Nameless apprentice", 137);
		Intern		intern;

		Form *ptr0 = intern.makeForm(REQ0, TARGET_NAME);
		Form *ptr = intern.makeForm(REQ1, "Bender");
		PresidentialPardonForm f3("Marvin");

		std::cout << "----------------------------------------------" << std::endl;
		ptr0->beSigned(apprentice);
		ptr0->beSigned(fersea);
		ptr0->execute(apprentice);
		ptr0->execute(fersea);
		std::cout << "----------------------------------------------" << std::endl;
		fersea.signForm(*ptr);
		ptr->beSigned(fersea);
		ptr->execute(fersea);
		std::cout << "----------------------------------------------" << std::endl;
		apprentice.signForm(f3);
		fersea.signForm(f3);
		f3.execute(fersea);
		std::cout << "----------------------------------------------" << std::endl;

		delete ptr0;
		delete ptr;
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
	catch (Intern::NoFormFound &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------------------------------------------" << std::endl;
	}

	return (0);
}