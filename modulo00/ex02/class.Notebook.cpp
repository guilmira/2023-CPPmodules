/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:15:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/18 15:38:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/* Class DEFINITION. 
* DEFINICIÓN: to code the actual function. 
* The function behaviour within the class is specified. */

/* return is written only for legibility´s sake since
* Constructor and destructors do not have return value.  */

/** CONSTRUCTOR :  */
Notebook::Notebook() 
	: _command(0)   //Initializer List. list all members in order, and in brackets, the value.
{
	std::cout << "Constructor called. Notebook class instantiated. ";
	std::cout << "Notebook running." << std::endl;
	return ;
}

/** DESTRUCTOR :  */
Notebook::~Notebook()
{
	std::cout << "Destructor called. Notebook class destroyed." << std::endl;
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



void	Notebook::read_command(void)
{
	std::string command;

	std::cout << "Awaiting command, ADD, SEARCH or EXIT:" << std::endl;
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
	


	this->_command = 0;
}
