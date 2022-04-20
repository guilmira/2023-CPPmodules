/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.show.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:11:53 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 18:12:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

#define HEADERS "+----------+----------+----------+----------+"
#define FORMAT_LINE "+----------+----------+----------+----------+"
#define WIDTH 10
#define CO "|"

static void	print_headers()
{
	std::string array[4];
	array[0] = F1;
	array[1] = F2;
	array[2] = F3;
	array[3] = F4;
	for (int i = 0; i < MAX_FIELDS - 1; i++)
		std::cout << std::setw(WIDTH + 1) << array[i];
	std::cout << std::endl;
}

void Notebook::show_contacts(int total) const
{
	int			i;
	int			j;
	std::string	str;

	if (this->_total < 1)
	{
		std::cout << "No contacts stored." << std::endl;
		return ;
	}
	i = -1;
	print_headers();
	while (++i < total)
	{
		j = -1;
		this->_print_string(FORMAT_LINE);
		for (int j = 0; j < MAX_FIELDS - 1; j++)
		{
			str = this->array_of_contacts[i].getData(j);
			std::cout << CO;;
			if (str.size() > 10)
				std::cout << str.substr(0, 9) << ".";
			else
				std::cout << std::setw(WIDTH) << str;
			
		}
		std::cout << CO;
		std::cout << std::endl;

		
	}
		
	
}
