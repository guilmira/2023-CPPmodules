/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:10:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/20 10:57:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/* void ft_leaks(void)
{
	system("leaks contacts");
} */

/** EXECUTION : ./contacts
 * This program will run a contact book.
 * ADD, SEARCH and EXIT accepted.									*/
int main(void)
{
	Notebook notebook1;
	//atexit(ft_leaks);
	while (1)
	{
		notebook1.read_command();
		notebook1.execute_command();
	}
	//std::cout << std::setw(2);

	/* std::string yolo = "hey_whats_going_on";

	std::string str(5, '9');

	std::cout << yolo << std::endl;
	std::cout << str << std::endl; */

	//std::cout << notebook1.getValue() << std::endl;
	return (0);
}

/* int main(void)
{
	std::string prueba("inicializando str");
	//es la manera correcta, para que no lo haga dos veces

	//el constructor reserva memoria (libera en el caso de que estuviese ocupada)
	y acontinuacion reserva.

	Tambien se puede realizar luego
	prueba = "esto es una prueba";
	el operador = esta sobrecargado, utiliza una funcion que seria:
	prueba.ft_strdup("esto es una prueba");
	esta funcion miembro, escribe el atributo string_value de la clase str.


	std::string prueba;
	//std::string prueba("hello");

	prueba = "hello";
	print_string(prueba); //como puede saber la direccion la funcion?
	//en que momento saca la direccion de la instancia?
} */