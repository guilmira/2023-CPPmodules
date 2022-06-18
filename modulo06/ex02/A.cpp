/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

A::A()
{
	log("A default constructed");;
}

A::~A()
{
	log("A destructed");
}

A::A(A const &src)
{

	*this = src;
	log("A copy constructed.");
}

A & A::operator=(A const &rhs)
{
	log("A assigned.");
	if (this != &rhs)
	{
		;
	}
	return (*this);
}
