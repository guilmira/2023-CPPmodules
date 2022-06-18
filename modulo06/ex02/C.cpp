/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

C::C()
{
	log("C default constructed");;
}

C::~C()
{
	log("C destructed");
}

C::C(C const &src)
{

	*this = src;
	log("C copy constructed.");
}

C & C::operator=(C const &rhs)
{
	log("C assigned.");
	if (this != &rhs)
	{
		;
	}
	return (*this);
}
