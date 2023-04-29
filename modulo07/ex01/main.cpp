/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/29 11:50:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/* Typedef of how it would be done without templates
Is just applying functions in a forloop. */
typedef void (*myType)(int &);
void	ft_add(int &x) { ++x; }
void	ft_iter(int *array, int size, myType function)
{
	for (int i = 0; i < size; i++)
		function(array[i]);
}

/* Here the exercise begins. */
template<typename T>
void	ft_test(T *array, int size)
{
	std::cout << "Printing:" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << *(array + i) << " ";
	std::cout << std::endl;
	std::cout << "template printing:" << std::endl;
	iter(array, size, ft_print);
	std::cout << std::endl;
	std::cout << "Template ADD and template print" << std::endl;
	iter(array, size, template_add);
	iter(array, size, ft_print);
	std::cout << std::endl;
	std::cout << "⭕OUTPUT⭕" << std::endl;
}

int main(void)
{
	int		*array;
	void	(*func_ptr)(int &);
	
	func_ptr = &ft_add;
	array = new int[10];
	for (size_t i = 0; i < 10; i++)
		*(array + i) = i;
	std::cout << "Printing:" << std::endl;
	for (size_t i = 0; i < 10; i++)
		std::cout << *(array + i) << " ";
	std::cout << std::endl;
	std::cout << "Standard iter (NOT USING TEMPLATES) with printing (USING TEMPLATES):" << std::endl;
	ft_iter(array, 10, func_ptr);
	iter(array, 10, ft_print);
	std::cout << std::endl;
	std::cout << "Template iter" << std::endl;
	iter(array, 10, func_ptr);
	iter(array, 10, ft_print);
	std::cout << std::endl;
	std::cout << "⭕OUTPUT⭕" << std::endl;
	delete[] array;

	std::string	*array_of_strings;
	array_of_strings = new std::string[10];
	for (size_t i = 0; i < 10; i++)
		*(array_of_strings + i) = i + 'A';
	ft_test(array_of_strings, 10);
	delete[] array_of_strings;

	char	*array_of_char;
	array_of_char = new char[10];
	for (size_t i = 0; i < 10; i++)
		*(array_of_char + i) = i + 'a';
	ft_test(array_of_char, 10);
	delete[] array_of_char;
}