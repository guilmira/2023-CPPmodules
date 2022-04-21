/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:10:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/21 11:55:40 by guilmira         ###   ########.fr       */
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
typedef std::vector<int>				intees;
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

	std::vector<Account> 					array_de_accounts;
	

	int array_de_ints[] = {1, 2, 3 , 4 , 5};
	int sz(sizeof(array_de_ints) / sizeof(int));
	
	std::vector<int> array2(6, 99);

	intees		array(array_de_ints, array_de_ints + sz);
	std::cout << array[4] << std::endl;
	
	std::cout << array2[5] << std::endl;
	return (0);
}