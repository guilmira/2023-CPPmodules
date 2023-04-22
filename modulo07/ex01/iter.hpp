/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:21:21 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/22 22:38:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void	ft_print(T &x)
{ 
	std::cout << " " << (x); 
}

template<typename T>
void	template_add(T &x)
{
	x++;
}

/* std::cout << "si le metes un string llamo a la especialización y aqui no ha pasado nada. Si no la tuviese, te salta el compilador." << std::endl;
 */
template<>
void	template_add(std::string &x)
{
	std::cout << "cant" << std::endl;
	(void) x;
}

template<typename T>
void iter(T *array, int size, void (*function)(T & ))
{
	for (int i = 0; i < size; i++)
	{
		function(array[i]);
	}
}
