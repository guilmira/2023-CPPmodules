/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>


typedef std::vector<int> myVector;
typedef std::deque<int> myDeque;
/* CLASS DECLARATION. */
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(char **argv, std::string const & line, int totalElements);
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe & operator=(PmergeMe const &rhs);

		std::string const &	getLine() const;
		void				setLine(std::string const &line);
		
		myVector sortMI(myVector vector);
		myDeque DequeSortMI(myDeque deque);

		std::vector<int>	_before;
		std::deque<int>		_beforeDeque;

	private:
		std::string			_line;
		int					_totalElements;

		void	ilog(const std::string & name, const std::string & msg) const;

};

#endif
