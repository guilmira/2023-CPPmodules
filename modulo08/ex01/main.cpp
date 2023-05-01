/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:32 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/01 18:14:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#define NB 10	
int main(void)
{

	Span big(NB);

	big.fillSpan(1, 1983725972, NB);
	big.printSpan();
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	std::cout << "longest: " << big.longestSpan() << std::endl;

	Span s(7);

	s.addNumber(49);
	s.addNumber(33);
	s.addNumber(3);
	s.addNumber(42);
	s.addNumber(39);
	s.addNumber(22);
	s.addNumber(0);
	try
	{
		s.addNumber(33);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	s.printSpan();
	std::cout << "shortest: " << s.shortestSpan() << std::endl;
	std::cout << "longest: " << s.longestSpan() << std::endl;

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
