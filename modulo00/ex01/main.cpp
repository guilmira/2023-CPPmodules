/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:10:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 11:00:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"



/** EXECUTION : ./contacts
 * This program will run a contact book.
 * ADD, SEARCH and EXIT accepted.									*/
int main(void)
{
	Notebook notebook1;
	
	while (1)
	{
		notebook1.read_command();
		notebook1.execute_command();
	}
	std::cout << notebook1.getValue() << std::endl;
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