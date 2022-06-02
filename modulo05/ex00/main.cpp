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



int	main(void)
{
	
	{
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat fersea("fersea", 149);
		//Bureaucrat fer("fersea", 152);
		std::cout << ++fersea << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------------------------------------------" << std::endl;
	Bureaucrat *ptr; 
	try
	{
		ptr = new Bureaucrat("fersea", 150);
		std::cout << ++(*ptr) << std::endl;
		Bureaucrat conci("fersea", 120); //skips it all together; this is because the exception has been thrown
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		delete ptr;
		std::cout << e.what();
	}
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat fersea("fersea", 2);
		std::cout << --fersea << std::endl;
		std::cout << --fersea << std::endl;

	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------------------------------------------" << std::endl;
	}

	return (0);
}