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

//#include "Bureaucrat.hpp"

#include <iostream>
#include "Conver.hpp"

static void	log(std::string str)
{
	std::cout << str << std::endl;
}

/* dynamic casting is mainly used for safe downcasting at run time. 
To work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast works only polymorphic base class 
because it uses this information to decide safe downcasting. */
	//mete c+ 11 y modificar el makefile
int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		log("Execution accepts only one argument.");
		return (1);
	}
	Conver con(argv[1]);
	con.display();
	return (0);
}