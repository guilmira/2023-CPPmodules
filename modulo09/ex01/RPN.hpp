/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <string>
#include <stack>


#define ADDITION '+'
#define SUBSTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'

/* CLASS DECLARATION. */
class RPN
{
	public:
		RPN();
		RPN(std::string const & name, std::string const & line);
		~RPN();
		RPN(RPN const &src);
		RPN & operator=(RPN const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

		void				buildStack();


	private:
		std::string			_name;
		std::stack<int>		_stack;
		std::string			_line;

		void	ilog(const std::string & name, const std::string & msg) const;

};

#endif
