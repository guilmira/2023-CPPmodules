/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:02:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/18 10:05:25 by guilmira         ###   ########.fr       */
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
	std::string str;

	i = -1;
	while(++i < FIELDS)
	{
		print_msg("Type the following category:");
		std::cout << this->categories[i] << std::endl;
		std::cin >> str;
		this->field[i] = str;

		//std::cout << this->field[i] << std::endl;
	}
}

void	Contact::show_fields(void) const
{
	int	i;

	i = -1;
	while(++i < FIELDS)
		std::cout << this->field[i] << std::endl;
}

