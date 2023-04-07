/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:53:23 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 10:54:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
class Warrior
{
	public:
		T _array[4];
};

int main(void)
{
	Warrior<int> w;
	std::cout << w._array[0] << std::endl;

	
	
	return (0);
}
