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

/* CLASS DECLARATION. */
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(std::string const & name);
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe & operator=(PmergeMe const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

	private:
		std::string _name;

		void	ilog(const std::string & name, const std::string & msg) const;

};

#endif
