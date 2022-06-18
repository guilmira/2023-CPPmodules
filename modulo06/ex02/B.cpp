/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

B::B()
{
	log("B default constructed");;
}

B::~B()
{
	log("B destructed");
}

B::B(B const &src)
{

	*this = src;
	log("B copy constructed.");
}

B & B::operator=(B const &rhs)
{
	log("B assigned.");
	if (this != &rhs)
	{
		;
	}
	return (*this);
}
