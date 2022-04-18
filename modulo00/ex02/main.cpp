/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:10:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/18 15:13:09 by guilmira         ###   ########.fr       */
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
	

	std::cout << notebook1.getValue(2) << std::endl;
	return (0);
}