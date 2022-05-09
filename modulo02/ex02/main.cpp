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
	Fixed		a(1);
	Fixed z = Fixed(5.05f);
	Fixed x = Fixed(2);
	std::cout << "aqui\n";

	//PENDIENTE IMPLEMENTAR MULTIPLICACION
	Fixed const b(z * x);

std::cout << "primero" << std::endl;
//llama al destructor al devolver una clase. mirar como funciona lo de a++ en CPP
	std::cout << a++ << std::endl;
	//std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::min(a,b) << std::endl;
	std::cout << Fixed::max(b,a) << std::endl;

	return (0);
}