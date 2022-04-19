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
	while (++i < total)
	{
		j = -1;
		//print_headers()
		while (++j < MAX_FIELDS - 1)
		{
			str = array_of_contacts[i].getData(j);
			std::cout << str;
			std::cout << "    ";
		}
		std::cout << std::endl;
	}
}

/* Cada columna debe tener 10 caracteres de ancho, estar alineada a la derecha
y separada por el caracter “|”. Cualquier salida que supere el ancho de la
columna, es truncada y el último carácter imprimible es reemplazado por un
punto (“.”). */