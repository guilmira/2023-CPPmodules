/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int N);
		//Array(T const & ptr);
		~Array();
	/* 	Array(Array const &src);
		Array & operator=(Array const &rhs); */

		T const &		getPtr() const;
		void			setPtr(T const &ptr);

		int const &		getSize() const;
		void			setSize(int const &size);

		void ilog(const std::string & msg)
		{
	
			std::cout << "[Class]Array" << msg << std::endl;
		}

	private:
		T	*_ptr;
		int	_size;
};

#endif
