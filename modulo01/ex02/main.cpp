/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 20:00:55 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define MSG "HI THIS IS BRAIN"

void ft_leaks(void)
{
	system("leaks zombies");
}

int	main(void)
{
	std::string str(MSG);
	std::string *stringPTR;
	

	stringPTR = NULL;
	stringPTR = &str;

	/* Task1 */
	std::cout << "Address using pointers: " ;
	std::cout << stringPTR << std::endl;

	std::cout << "Value using pointers: " ;
	std::cout << *stringPTR << std::endl; 
	//Note: operator << loaded in the class string. 
	//Thats why *ptr displays the string, which is nothing more than an atribute member.

	/* REGERENCES in C++ */
	//A reference has to be assigned in the moment of its creation.
	std::string& stringREF = str;

	/* Task2 */
	std::cout << "Address using reference: " ;
	std::cout << &stringREF << std::endl;
	std::cout << "Value using reference: " ;
	std::cout << stringREF << std::endl;

	//References are a sort of syntatic sugar: 
	/* A variable declared as a reference
	as is stringREF in this case, becomes
	an alternative name for an existing variable.
	Its equivalent to a pointer (so its just an adress)
	but its at all times DEREFERENCED. 
	Its main use is to feed it to functions as input, that
	way a copy of the object will not be created and direct access
	to the object will be possible. */
	//atexit(ft_leaks);
	return (0);
}