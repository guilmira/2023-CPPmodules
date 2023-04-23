/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/23 19:05:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include<array> 
/* For evaluation purposes */

int main(void)
{
	char *b = new char;
	std::cout << *b << std::endl;



	std::array<int, 2> clase;
	std::cout << clase[0] << std::endl;

	Array<int> mine;
	std::cout << mine.getSize() << std::endl;
	std::cout << mine.getPtr() << std::endl;

	/* Array<int> mine1(5);
	std::cout << mine1.getSize() << std::endl;
	std::cout << mine1.getPtr() << std::endl; */

}
