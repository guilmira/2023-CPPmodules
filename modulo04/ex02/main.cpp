/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/17 08:29:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

void ft_leaks(void)
{
	system("leaks -q animal");
}

int	main(void)
{
	atexit(ft_leaks);
	std::cout << "----------------------------------------------" << std::endl;
	Cat miau;
	//Animal ani; //En el momento en el que una funcion de la clase la transformas en pure virtual, la clase pasa a ser abstracta y no se puede instanciar el objeto.
	//si que puede crearse, cuando se crea por ejemplo un objeto de la clase Cat.
	Cat second_miau(miau);
	second_miau.makeSound();
	std::cout << "----------------------------------------------" << std::endl;

	return (0);
}