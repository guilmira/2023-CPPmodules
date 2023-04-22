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
class Array
{
	public:
		Array();
		Array(std::string const & name);
		~Array();
		Array(Array const &src);
		Array & operator=(Array const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

	
	private:
		std::string _name;
};

#endif
