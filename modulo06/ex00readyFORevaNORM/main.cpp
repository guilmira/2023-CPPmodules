/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/16 17:15:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Caster.hpp"

/* Main fit for evaluation */
int	main(int argc, char **argv)
{
	Caster caster(argv[1]);
	
	if (argc != 2)
	{
		std::cout << "2 arguments allowed." << std::endl;
		return (0);
	}
	caster.InputtoChar();
	caster.displayAll();
	return (0);
}

/* Main fit for testing */
#include <fstream>
/* int	main(void)
{
	std::ifstream input("test.txt");
	std::string line;
	Caster *c;
	
	while (std::getline(input, line))
	{
		std::cout << "----------------------------" << std::endl;
		c = new Caster(line);
		c->InputtoChar();
		c->displayAll();
		delete c;
	}
	return (0);
} */
