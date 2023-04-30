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

		void						addNumber(int i);
		int							shortestSpan();
		int							longestSpan();

	private:
		std::vector<int>	_v;

		Span();
		void	ilog(const std::string & msg) const;

};

#endif
