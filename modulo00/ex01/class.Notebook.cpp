/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:15:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 15:13:48 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/* Class DEFINITION. 
* DEFINICIÓN: to code the actual function. 
* The function behaviour within the class is specified. */

/* return is written only for legibility´s sake since
* Constructor and destructors do not have return value.  */

/** CONSTRUCTOR */
Notebook::Notebook()
	: _command(0), _total(0)   //Initializer List. list all members in order, and in brackets, the value.
{
	this->_print_string("Constructor called. Notebook class instantiated. ");
	this->_print_string("Notebook running.");
	return ;
}

/** DESTRUCTOR */
Notebook::~Notebook()
{
	this->_print_string("Destructor called. Notebook class destroyed.");
	return ;
}

int	Notebook::getValue(void) const
{
	return (this->_command);
}

void	Notebook::setValue(int x)
{
	if (x >= 0)
		this->_command = x;
	else
		std::cout << "not allowed for this class" << std::endl;
}


/** SYNTAX EXPLANATION : 
 * &str en la definicion de la funcion. Nuevo operador. Lo que está indicando
 * es que va a recibir una direccion de la instancia.
 * 
 * Es literalmente equivalente a 
 * void	print_string(std::string *str) {
 * std::cout << *str << std::endl; }
 * Pasamos una direccion y dereferenciamos. La dereferencia se hace mas tarde sin necesidad
 * de escribir (*str) debido a la sobrecarga del operador. 
 * 
 * ¿Por qué pasarlo por referencia? Por memoria y optimizacion. Duplicar la clase es mas costoso
 * comutacionalmente que pasar un puntero.
 * 
 * Todo lo que este a la izquierda de const, es lo que es constante. East notation.
 * En este caso, es el valor de la clase. NO es el puntero como tal.
 * void	print_string(std::string * const str) el puntero es constante. no la clase.
 * void	print_string(std::string const *str) la clase es constante.
				
				
				*/
void	Notebook::_print_string(std::string const &str)
{
	std::cout << str << std::endl; 
}


void	Notebook::read_command(void)
{
	std::string command;

	this->_print_string("Awaiting command, ADD, SEARCH or EXIT:");
	std::getline(std::cin, command);
	if (!command.compare("ADD"))
		this->setValue(ADD);
	else if (!command.compare("SEARCH"))
		this->setValue(SEARCH);
	else if (!command.compare("EXIT"))
		this->setValue(EXIT);
	else
		this->setValue(NONE);
}

void	Notebook::execute_command(void)
{
	int command;

	command = this->getValue();
	if (command == EXIT)
		exit(0);
	else if (command == ADD)
	{
		add_contact(this->_total);
		if (this->_total < MAX_CONTACTS)
			this->_total++;
		//std::cout << this->_total << std::endl;
	}
	else if (command == SEARCH)
	{
		search_contact(this->_total);
		if (this->_total < MAX_CONTACTS)
			this->_total++;
		//std::cout << this->_total << std::endl;
	}
	this->_command = 0;
}

void Notebook::add_command(int index)
{
	Contact new_contact(index);

	//this->array_of_contacts = new_contact;
	new_contact.get_input();
	this->array_of_contacts[index] = new_contact;
	return ;
}
