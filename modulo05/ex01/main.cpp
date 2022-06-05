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

	//meterle mas pruebas	
int	main(void)
{
	{
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	fersea("Lady fersea", 39);
		Bureaucrat	apprentice("Witch apprentice", 120);

		Form		council_report("report", 40, 80);
		//Form		council_report3("report", 40, 151);
		Form		council_report2(council_report);

		fersea.signForm(council_report);
		council_report.beSigned(fersea);
		fersea.signForm(council_report);
		apprentice.signForm(council_report2);
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