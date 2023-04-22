/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/22 22:03:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int		ft_add(int &x) { return (++x); }

void	ft_iter(int *array, int size, int (*function)(int &))
{
	for (int i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

template<typename T, typename U, typename V>
void iter(T *array, U size, V function)
{
	for (U i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

/* si quisiese usar un typdef:
typedef int (*myType)(int &);
myType func_ptr = &ft_add; */

typedef int (*myType)(int &);
/* explicito. ni con esta linea de codigo compila. tiene que ir implicito*/
/* iter<int *, int, myType>(array, 10, func_ptr); */


int main(void)
{
	int	*array;
	int	(*func_ptr)(int &);
	
	std::cout << "Ejemplo sin templates. Iterar por un array y aplicar una función" << std::endl;
	func_ptr = &ft_add;
	array = new int[10];
	for (size_t i = 0; i < 10; i++)
		*(array + i) = i;
	for (size_t i = 0; i < 10; i++)
		std::cout << *(array + i) << " ";
	std::cout << "⭕OUTPUT⭕" << std::endl;
	ft_iter(array, 10, func_ptr);
	iter(array, 10, func_ptr);
	for (size_t i = 0; i < 10; i++)
		std::cout << *(array + i) << " ";


	std::string str("4");
	iter(array, str, func_ptr);
	for (size_t i = 0; i < 10; i++)
		std::cout << *(array + i) << " ";

	delete array;
}
