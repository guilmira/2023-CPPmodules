/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/23 16:18:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Caster.hpp"
void ft_leaks(void)
{
	system("leaks -q casts");
}

/* Main for evaluation */
int	main(int argc, char **argv)
{
	Caster *caster;
	if (argc != 2)
	{
		std::cout << "2 arguments allowed." << std::endl;
		return (0);
	}
	caster = new Caster(argv[1]);
	caster->InputtoChar();
	caster->displayAll();
	delete caster;
	return (0);
}

/* Main fit for testing */
/* #include <fstream>
int	main(void)
{
	atexit(ft_leaks);

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
	std::cout << "----------------------------" << std::endl;
	return (0);
} */
