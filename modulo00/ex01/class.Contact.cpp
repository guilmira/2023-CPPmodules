/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:02:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/17 15:09:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/* Class DEFINITION. 
* DEFINICIÓN: to code the actual function. 
* The function behaviour within the class is specified. */

/* return is written only for legibility´s sake since
* Constructor and destructors do not have return value.  */

/** CONSTRUCTOR :  */
Contact::Contact()
{
	std::cout << "construyendo" << std::endl;
	return ;
}

/** DESTRUCTOR :  */
Contact::~Contact()
{
	std::cout << "destruyendo" << std::endl;
	return ;
}

#define FIELDS 5

void	Contact::create_contact(void)
{
	int	i;
	char str[1000];

	i = -1;
	while(++i < FIELDS)
	{
		std::cout << this->field[i] << std::endl;
		std::cin >> str;
		this->field[i] = str;
	}
}

void	Contact::show_fields(void) const
{
	int	i;

	i = -1;
	while(++i < FIELDS)
		std::cout << this->field[i] << std::endl;
}

