/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:15:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 19:48:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/* Class DEFINITION. */

/** CONSTRUCTOR */
Notebook::Notebook()
	: _command(0), _total(0)
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

void	Notebook::exit_contacts(void)
{
	int i;

	i = -1;
	if (this->_total)
		while (++i < MAX_CONTACTS)
			this->array_of_contacts[i].~Contact();
	exit(0);
}

void	Notebook::execute_command(void)
{
	int command;
	int position;

	position = 0;
	command = this->getValue();
	if (command == EXIT)
		exit_contacts();
	else if (command == ADD)
	{
		position = this->_total % MAX_CONTACTS;
		this->add_contact(position);
		this->_total++;
	}
	else if (command == SEARCH)
	{
		if (this->_total < MAX_CONTACTS)
			this->show_contacts(this->_total);
		else
			this->show_contacts(MAX_CONTACTS);
	}
	this->_command = 0;
}

void Notebook::add_contact(int index)
{
	Contact new_contact(index);

	new_contact.prompt_input();
	if (&this->array_of_contacts[index])
		this->array_of_contacts[index].~Contact();
	this->array_of_contacts[index] = new_contact;
	return ;
}

