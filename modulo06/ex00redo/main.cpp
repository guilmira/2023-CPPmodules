/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/16 14:15:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Caster.hpp"

//main para la evaluacion. revisar antes de evaluaion comentarios etc.
/* int	main(int argc, char **argv)
{
	Caster caster(argv[1]);
	
	if (argc != 2)
	{
		std::cout << "2 arguments allowed." << std::endl;
		return (0);
	}
	caster.display();
	return (0);
} */

#include <fstream>
int	main(void)
{
	std::ifstream input("test.txt");
	std::string line;
	Caster *c;
	
	while (std::getline(std::cin, line))
	{
		std::cout << "----------------------------" << std::endl;
		c = new Caster(line);
		c->InputtoChar();
		c->displayAll();
		delete c;
	}
	return (0);
}

/* Límite mínimo de un char: -128
Límite máximo de un char: 127
Límite mínimo de un unsigned char: 0
Límite máximo de un unsigned char: 255
Límite mínimo de un short: -32768
Límite máximo de un short: 32767
Límite mínimo de un unsigned short: 0
Límite máximo de un unsigned short: 65535
Límite mínimo de un int: -2147483648
Límite máximo de un int: 2147483647
Límite mínimo de un unsigned int: 0
Límite máximo de un unsigned int: 4294967295
Límite mínimo de un long long: -9223372036854775808
Límite máximo de un long long: 9223372036854775807
Límite mínimo de un unsigned long long: 0
Límite máximo de un unsigned long long: 18446744073709551615
Límite mínimo de un float: -3.40282347e+38
Límite máximo de un float: 3.40282347e+38
Límite mínimo de un double: -1.7976931348623158e+308
Límite máximo de un double: 1.7976931348623158e+308 */