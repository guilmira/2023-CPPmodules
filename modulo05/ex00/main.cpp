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
		Bureaucrat fersea("fersea", 150);
		std::cout << fersea << std::endl;

		Bureaucrat conci("fersea", 160);

	}
	catch (std::exception &e)
	{
		std::cout << "grade to low\n" << e.what();
	}

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;
	}

	return (0);
}