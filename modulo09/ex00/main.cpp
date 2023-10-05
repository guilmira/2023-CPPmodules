/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:28:42 by guilmira          #+#    #+#             */
/*   Updated: 2023/10/03 18:17:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* __probar el constructor copia con la copia de map */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}
	try
	{
		BitcoinExchange exchanger("exchanger", std::string(DATABASE));
		exchanger.outputResult(std::string(argv[1]));	
	
	}
	catch (const std::exception & e)
	{
    	std::cerr << "Exception: " << e.what() << std::endl;
		exit (1);
	}
	return 0;
}