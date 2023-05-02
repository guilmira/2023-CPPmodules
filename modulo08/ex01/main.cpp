/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:32 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/02 12:15:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#define NB 10000

/* The exercise is resolved in 2 ways.
1. Own ft_sort, O(n2)
2. Using STDalgorithm, O(nlog(n)) */
int main(void)
{

	Span big(NB);

	big.fillSpan(1, 1983725972, NB);
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	big.printSpan();	
	std::cout << "longest: " << big.longestSpan() << std::endl;

	Span s(7);

	s.addNumber(49);
	s.addNumber(-33);
	s.addNumber(0);
	s.addNumber(42);
	s.addNumber(39);
	s.addNumber(-39);
	s.addNumber(110);
	try
	{
		s.addNumber(33);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "shortest: " << s.shortestSpan() << std::endl;
	std::cout << "longest: " << s.longestSpan() << std::endl;
	s.printSpan();

	return (0);
}

/* Main of the evaluation */
/* int main()
{
	Span sp = Span(5);
	
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
} */
