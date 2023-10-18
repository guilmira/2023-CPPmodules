/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:28:42 by guilmira          #+#    #+#             */
/*   Updated: 2023/10/18 15:40:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

// 3 7 1 9 2 4

void insertionSort(std::vector<int> &set)
{
	int temp;

	temp = 0;
	for (size_t i = 0; i < set.size(); i++)
	{
		
		std::cout << i << std::endl;
		for (size_t j = 0; j < i; j++)
		{
			std::cout << "⭕OUTPUT⭕" << std::endl;
			if (set[i] < set[i - j])
			{
				set[i] = set[i - j];
			}
			else
			{
				set[i - j] = temp;
				break;
			}
		}
	}
}


int main(int argc, char **argv)
{
	// int int = 2147483647; 
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	std::string line(argv[1]);
	try
	{
		PmergeMe merge(argv, line, argc - 1);
		merge.displayBefore();
		// merge.displayAfter();
		// merge.displayEnd();

		merge.mergeInsertionSort();
		merge.displayAfter();		

	}
	catch (const std::exception & e)
	{
    	std::cerr << "Exception: " << e.what() << std::endl;
		exit(1);
	}
	return 0;
}