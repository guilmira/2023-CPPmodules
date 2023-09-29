/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:28:42 by guilmira          #+#    #+#             */
/*   Updated: 2023/09/29 21:46:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


void	ftExit(std::string msg)
{
	std::cout << msg << std::endl;
	exit(1);
}

	typedef std::map<std::string, float>	myMap;
	typedef myMap::iterator					mapIter;

/* __probar el constructor copia con la copia de map */
int main(int argc, char **argv)
{
	

	if (argc != 2)
		ftExit("Error: could not open file.");
	try
	{
		BitcoinExchange exchanger("exchanger", std::string(DATABASE), std::string(argv[1]));
		exchanger.outputResult();	
	
	}
	catch (const std::exception & e)
	{
    	std::cerr << "Exception: " << e.what() << std::endl;
		exit (1);
	}
	return 0;
}