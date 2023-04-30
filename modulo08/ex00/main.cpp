/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:32 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/30 15:00:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <array>
#include <list>
#define MAX_SIZE 10


template<typename T>
void ft_test(T const &container, typename T::const_iterator iterator_searched)
{
	std::vector<int>::const_iterator	result_iterator;

	std::cout << "----------" << std::endl;
	result_iterator = easyfind(container, *iterator_searched);
	std::cout << "found value: ";
	std::cout << *result_iterator << std::endl;
	std::cout << "position: ";
	std::cout << std::distance(container.cbegin(), result_iterator) << std::endl;
	std::cout << "----------" << std::endl;
}

template<typename T>
void ft_test_int(T const & container, int value_searched)
{
	std::vector<int>::const_iterator	result_iterator;

	std::cout << "----------" << std::endl;
	result_iterator = easyfind(container, value_searched);
	std::cout << "found value: ";
	std::cout << *result_iterator << std::endl;
	std::cout << "position: ";
	std::cout << std::distance(container.cbegin(), result_iterator) << std::endl;
	std::cout << "----------" << std::endl;
}


int main(void)
{
	std::cout << "CONTAINER VETOR OF SIZE: " << MAX_SIZE << std::endl;
	std::vector<int> v;

	std::cout << "Fill container and print it (using iterators so its value for any type of container):" << std::endl;
	for (size_t i = 0; i < MAX_SIZE; i++)
		v.push_back(i + 3*i);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::vector<int>::const_iterator	iterator_searched = v.end() - 3; 
	int									value_searched = 0;
	std::cout << "TESTS-------------------------------------------------" << std::endl;
	try
	{
		ft_test(v, iterator_searched);
		ft_test_int(v, value_searched);
		iterator_searched = v.cbegin() + 1;
		ft_test(v, iterator_searched);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "CONTAINER linked list OF SIZE: " << MAX_SIZE << std::endl;
	std::list<int> list;

	for (size_t i = 0; i < MAX_SIZE; i++)
		list.push_back(i * 666);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::list<int>::const_iterator result;

	int value;
	value = 1998;
	result = easyfind(list, value);
	std::cout << "searching for " << value << " position of number is : " << std::distance(list.cbegin(), result) << std::endl;

	result = easyfind(list, *std::next(list.cbegin()));
	std::cout << "searching for " << *std::next(list.cbegin()) << " position of number is : " << std::distance(list.cbegin(), result) << std::endl;

	result = easyfind(list, *std::prev(list.cend()));
	std::cout << "searching for " << *std::prev(list.cend()) << " position of number is : " << std::distance(list.cbegin(), result) << std::endl;

	return (0);
}

/* Note 0: trying to use iterators beyond container limits will cause undefined behaviour */

/* Note: why do i use cbegin in std::distance?
because it changes the overload of the function.

I had to use constant iterators, cause im passing to easyfind a container by const ref.
since there is the "promess" that i will not modify the content of the reference" the compailer enforces me to make the iterator const_iterators. Therfore, my return value is a const iterator. Knwoing this, std::distance has to work with const_iterators. and the overload for that, requires that cbegin() gives back a const iterator. So i can use begin(), that gives me a normal iterator.
The "soution" or second option to avoid all of this, is just passing the container by reference and avoiding working with constant things.
In general, is advise to work with constant iterators, but c++ libraries often work with normal iterators. */