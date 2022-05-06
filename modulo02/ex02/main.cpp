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
	Fixed		a;
	Fixed const b(10.0f);
	Fixed c(10.0f);
	Fixed const d(b);

	std::cout << "hatever" << std::endl;
	Fixed z;
	//std::cout << c << std::endl;
	z = c + b;
std::cout << z << std::endl;

std::cout << c << std::endl;
	return (0);
}