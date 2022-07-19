/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/19 12:57:55 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	fersea("Lady fersea", 39);
		Bureaucrat	apprentice("Witch apprentice", 120);

		Form		council_report("Agency form 99", 40, 80);
		//Form		council_report3("report", 40, 151); //WILL throw exeption.
		Form		council_report2(council_report);

		//council_report.beSigned(apprentice); //WILL throw exeption.
		fersea.signForm(council_report);
		std::cout << "\n";
		council_report.beSigned(fersea);
		std::cout << "\n";
		fersea.signForm(council_report);
		std::cout << "\n";
		apprentice.signForm(council_report2);
		std::cout << "\n";
		fersea.signForm(council_report2);
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