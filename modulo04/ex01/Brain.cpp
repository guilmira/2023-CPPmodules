/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/17 12:11:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

Brain::Brain()
{
	log("Default constructor----------		----------for BRAIN.");

	std::stringstream out;
	for (int i = 0; i < N; i++)
	{
		out << i;
		this->_ideas[i] = out.str();
	}
	return ;
}

Brain::~Brain()
{
	log("Destructor---------		----------for BRAIN.");
	return ;
}

Brain::Brain(Brain const &src)
{
	log("Copy constructor---------		----------for BRAIN.");
	*this = src;
}

Brain & Brain::operator=(Brain const&rhs)
{
	log("Assignation---------		----------for BRAIN.");
	for (int i = 0; i < N; i++)
	{
		this->_ideas[i] = rhs.getIdeas(i);
	}
	return (*this);
}

/* --------------------------------- GET | SET --------------------------------- */
std::string const & Brain::getIdeas(const int index) const
{
	if (index < 0 || index > 99)
	{
		log("Out of array");
		return(this->_ideas[0]);
	}
	return(this->_ideas[index]);
}

void Brain::setIdeas(const int index, std::string const &src)
{
	std::string str(src);//paso siempre los objetos por const reference.
	//una vez dentro de la función, ya los duplico si los necesito.

	if (index < 0 || index > 99)
	{
		log("Out of array");
		return ;
	}
	this->_ideas[index] = str;
}