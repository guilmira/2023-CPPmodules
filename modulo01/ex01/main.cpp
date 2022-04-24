/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 19:57:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ARRAY_NBR 6

void ft_leaks(void)
{
	system("leaks zombies");
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *ptr;

	ptr = NULL;
	if (N < 1)
		return (ptr);
	
	ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
		(ptr + i)->setName(name);
	return (ptr);
}

int	main(void)
{
	Zombie *ptr;

	ptr = zombieHorde(ARRAY_NBR, "Thriller");
	for (int i = 0; i < ARRAY_NBR; i++)
		(ptr + i)->announce();
	delete [] ptr;
	atexit(ft_leaks);
	return (0);
}