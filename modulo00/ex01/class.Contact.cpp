/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:19:02 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 15:12:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/** CONSTRUCTOR */
Contact::Contact() //: _data[0](0) _data[1](0) se podria hacer esto?
	: _index(0)
{
	std::cout << "-Contract class instantiated- " << std::endl;
	//cuando crees la clase que llame a una funcion de la clase de añadir
	return ;
}

/** CONSTRUCTOR overload  */
Contact::Contact(int i)
	: _index(i)
{
	std::cout << "construyendo overload" << std::endl;
	std::cout << this->_index << std::endl;
	
	_fields[0] = "0";
	_fields[1] = "1";
	_fields[2] = "2";
	_fields[3] = "3";
	_fields[4] = "4";
	return ;
}

/** DESTRUCTOR */
Contact::~Contact()
{
	return ;
}

void	Contact::get_input(void)
{
	int i;
	int index;

	std::string line;
	i = -1;
	while (++i < MAX_FIELDS)
	{
		std::cout << "Type the field " << this->_fields[i] << std::endl;
		std::getline(std::cin, line);
		this->_data[i] = line;
	}
}