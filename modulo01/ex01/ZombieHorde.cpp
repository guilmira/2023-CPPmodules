/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:05:09 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 19:05:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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