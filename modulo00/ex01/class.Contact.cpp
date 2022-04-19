/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:19:02 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 18:22:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/** CONSTRUCTOR */
Contact::Contact()
	: _index(0)
{
	return ;
}

/** CONSTRUCTOR overload  */
Contact::Contact(int i)
	: _index(i)
{
	std::cout << "Instance of contact nº";
	std::cout << this->_index  << std::endl;
	
	_fields[0] = F1;
	_fields[1] = F2;
	_fields[2] = F3;
	_fields[3] = F4;
	_fields[4] = F5;
	return ;
}

/** DESTRUCTOR */
Contact::~Contact()
{
	return ;
}

void	Contact::prompt_input(void)
{
	int i;
	int index;

	std::string line;
	i = -1;
	while (++i < MAX_FIELDS)
	{
		std::cout << "Type the field - " << this->_fields[i] << std::endl;
		std::getline(std::cin, line);
		this->setData(i, line);
	}
}

std::string	Contact::getData(int i) const
{
	return(this->_data[i]);
}

void	Contact::setData(int i, std::string str)
{
	this->_data[i] = str;
}