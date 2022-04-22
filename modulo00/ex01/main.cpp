/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:10:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/22 12:35:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

/* void ft_leaks(void)
{
	system("leaks contacts");
} */

#include <vector>

class Account
{
	public:
		int z;

	private:
		int _z;

};

/** EXECUTION : ./contacts
 * This program will run a contact book.
 * ADD, SEARCH and EXIT accepted.									*/
int main(void)
{
	Notebook notebook1;
	//atexit(ft_leaks);
	while (0)
	{
		notebook1.read_command();
		notebook1.execute_command();
	}
	return (0);
}