/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/29 00:03:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <array> 
/* For evaluation purposes */

template <typename T>
static void bad_access(size_t index, Array<T> *instance)
{
	Array<T> a;


	a = *instance;
	try
	{
		a[index];
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

#define N 100
int main(void)
{
	

	std::cout << "Default string" << std::endl;
	Array<std::string> first;

	std::cout << first.getSize() << std::endl;
	std::cout << first << std::endl;
	std::cout << first.getPtr() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	bad_access(1, &first);
	bad_access(500, &first);
	std::cout << "-----------------------------" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "N size int" << std::endl;
	Array<int> second(N);
	for (size_t i = 0; i < N ; i++)
		second[i] = N - static_cast<int>(i);
	Array<int> third(second);
	std::cout << second[4] << std::endl;
	std::cout << third << std::endl;
	if (second[N - 1] == third[N - 1])
		std::cout << "⭕all is good⭕" << std::endl;
	bad_access<int>(N + 1, &second);
	//first = second; this wont fly. We are talking about different programmed classes.
	//U wouldnt try to do std::string a = z (z being Class Vector). well this is the same.
	std::cout << "-----------------------------" << std::endl;

}
