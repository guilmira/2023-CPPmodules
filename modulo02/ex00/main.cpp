/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:12:31 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/04 08:39:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	std::cout << "Address a: " << &a << std::endl;
	Fixed b(a);
	std::cout << "Address b: " << &b << std::endl;

	Fixed c;

	c = b;

	a.setRawBits(5);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	b = a;
	std::cout << b.getRawBits() << std::endl;
	std::cout << "Address b: " << &(b.operator=(a)) << std::endl;

	b.setRawBits(99);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;

	return (0);
}