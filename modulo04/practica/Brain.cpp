/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
static void ilog(const std::string & name, const std::string & msg)
{
	
	std::cout << "[Class]Brain - [Instance]" << name << " |	"\
	<< msg << std::endl;
}


/* --------------------------------- CONSTRUCTORS --------------------------------- */
Brain::Brain()
{
	ilog(getIdea(0), "Constructed⚪");
	for (int i = 0; i < 100; i++)
	{	
		setIdea(i, "TheIdea");
	}
	return ;
}


/* --------------------------------- DESTRUCTOR --------------------------------- */
Brain::~Brain()
{
	ilog(getIdea(0), "-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
Brain::Brain(Brain const &src)
{
	*this = src;
	ilog(getIdea(0), "Copy constructed");
	return ;
}
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
Brain & Brain::operator=(Brain const &rhs)
{
	int i;

	i = -1;
	ilog(getIdea(0), "[=] Assignation operator called");
	if (this != &rhs)
	{
		while (++i < 100)
		{
			this->_ideas[i] = rhs.getIdea(i);
		}
	}
	return (*this);
}
/* --------------------------------- GET | SET --------------------------------- */
std::string const & Brain::getIdea(int index) const
{
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 100)
		this->_ideas[index] = idea;
}
/* --------------------------------- METHODS --------------------------------- */

