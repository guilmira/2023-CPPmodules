/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conver.hpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVER_HPP
#define CONVER_HPP

#include <iostream>
#include <stdexcept>

class Conver
{
	public:
		Conver();
		Conver(std::string str);
		~Conver();
		Conver(Conver const &src);
		Conver & operator=(Conver const &rhs);

		std::string getArg() const;

		char		conChar() const;
		int			conInt() const;
		float		conFloat() const;
		double		conDouble() const;


		void display() const;


	private:
		std::string	_arg;
};

#endif
