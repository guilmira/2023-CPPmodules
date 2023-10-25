/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:28:42 by guilmira          #+#    #+#             */
/*   Updated: 2023/10/25 10:55:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

static void	displayEnd(int elements, std::clock_t *time)
{
	std::cout << "Time to process a range of " << elements << " elements with std::vector : " << time[1] - time[0] << " us" << std::endl;
	std::cout << "Time to process a range of " << elements << " elements with std::deque : " << time[3] - time[2] << " us" << std::endl;
	return ;
}

template <typename T>
static void	displayContainer(T const & container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end() ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::clock_t 		time[4];
	std::vector<int> 	sortedVec;
	std::deque<int> 	sortedDeque;
	
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	std::string line(argv[1]);
	try
	{
		PmergeMe merge(argv, line, argc - 1);

		std::cout << "Before:  ";
		displayContainer(merge._before);
		
		time[0] = std::clock();
		sortedVec = merge.sortMI(merge._before);
		time[1] = std::clock();

		std::cout << "After:   ";
		displayContainer(sortedVec);
		
		time[2] = std::clock();
		sortedDeque = merge.DequeSortMI(merge._beforeDeque);
		time[3] = std::clock();

		displayEnd(merge._before.size(), time);
	}
	catch (const std::exception & e)
	{
    	std::cerr << "Exception: " << e.what() << std::endl;
		exit(1);
	}
	return 0;
}