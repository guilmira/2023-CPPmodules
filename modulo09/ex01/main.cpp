/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:28:42 by guilmira          #+#    #+#             */
/*   Updated: 2023/10/05 15:05:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool			isMathOperand(char z)
{
	if (z == ADDITION)
		return true;
	if (z == SUBSTRACTION)
		return true;
	if (z == MULTIPLICATION)
		return true;
	if (z == DIVISION)
		return true;
	return false;
}

static bool		parserCorrect(std::string const &line)
{
	int		digits = 0;
	int		operators = 0;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (isdigit(line[i]))
			digits++;
		if (isMathOperand(line[i]))
			operators++;
		if ((isdigit(line[i]) || isMathOperand(line[i])) && (i + 1) != line.length())
			if (!isspace(line[i + 1]))
				return false;		
	}
	if (digits == operators + 1)
		return true;
	return false;

}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: worng argumen number. Exected: 1 arg" << std::endl;
		exit(1);
	}
	std::string line(argv[1]);
	if (!parserCorrect(line))
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	try
	{
		RPN notation(line);
	}
	catch (const std::exception & e)
	{
    	std::cerr << "Exception: " << e.what() << std::endl;
		exit(1);
	}
	return 0;
}