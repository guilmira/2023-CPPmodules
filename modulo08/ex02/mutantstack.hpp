/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <list>

/* CLASS DECLARATION. */
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(MutantStack const &src)
			: std::stack<T>::container_type::c(src.c)
		{
			return ;
		}
		MutantStack & operator=(MutantStack const &rhs)
		{
			if (this != &rhs)
				std::stack<T>::container_type::c = rhs.c;
		}

		/* From the stack definition. Inside_container is called container_type */
		/* Using typdefs for syntactic sugar */
		/* cant call it my_iterator, not allowed by subject main */
		typedef typename std::stack<T>::container_type								container_type;
		typedef typename std::stack<T>::container_type::iterator					iterator;
		typedef typename std::stack<T>::container_type::const_iterator				const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator		const_reverse_iterator;
		
		
		iterator begin(void) 					 { return (this->c.begin()); }
		iterator end(void) 						 { return (this->c.end()); }
		
		const_iterator cbegin(void) 			 { return (this->c.cbegin()); }
		const_iterator cend(void) 				 { return (this->c.cend()); }

		reverse_iterator rbegin(void) 	 	     { return (this->c.rbegin()); }
		reverse_iterator rend(void) 			 { return (this->c.rend()); }

		const_reverse_iterator crbegin(void) 	 { return (this->c.crbegin()); }
		const_reverse_iterator crend(void) 		 { return (this->c.crend()); }

	private:

};

#endif
