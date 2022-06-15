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
#include <string>

static void	display(char z, int i, float fl, double db)
{
	std::cout << "char:		" << z << std::endl;
	std::cout << "int:		" << i << std::endl;
	std::cout << "float:	" << fl << std::endl;
	std::cout << "double:	" << db << std::endl;
}

static void	log(std::string str)
{
	std::cout << str << std::endl;
}

int	main(int argc, char **argv)
{
	std::string arg;
	//mete c+ 11 y luego se lo quita. es con std::stoi(), acuerdate de no borrar la linea

	if (argc != 2)
	{
		log("Execution accepts only one argument.");
		return (1);
	}
	arg = argv[1];
	log(arg);

	char	z;
	int		nb;
	float	fl;
	double	db;

	nb = std::stoi(arg);
	z = static_cast<char>(nb);
	std::cout << nb << std::endl;

	fl = static_cast<float>(nb);
	db = static_cast<double>(db);


	display(z, nb, fl, db);
	return (0);
}