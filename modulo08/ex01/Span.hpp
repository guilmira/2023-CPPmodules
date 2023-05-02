/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define	SPAN_HPP

#include <iostream>
#include <string>
#include <vector>

/* CLASS DECLARATION. */
class Span
{
	public:
		Span(unsigned int N);
		~Span();
		Span(Span const &src);
		Span & operator=(Span const &rhs);

		std::vector<int> const &	getVector() const;
		void						setVector(std::vector<int> const &v);
		unsigned int				getSize() const;
		void						setSize(unsigned int size);
		unsigned int				getCounter() const;
		void						setCounter(unsigned int counter);

		void						addNumber(int value);
		void						fillSpan(int min, int max, unsigned int n);
		int							shortestSpan();
		int							longestSpan();

		void						printSpan() const;
		void						printVector() const;

		class SpanException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Exception -> Index out of bouds"); }
		};

	private:
		std::vector<int>	_v;
		unsigned int		_size;
		unsigned int		_counter;
		unsigned int		_flag;

		Span();
		void	ilog(const std::string & msg) const;
		void						fast_sorting();

};

#endif
