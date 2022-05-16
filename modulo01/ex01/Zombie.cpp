/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:33:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 19:19:18 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Class DEFINITION. */

#include "Zombie.hpp"
#define BRAIN "BraiiiiiiinnnzzzZ.."

static void	print_name(std::string const & name)
{
	std::cout << "<" << name << ">";
}

/** CONSTRUCTOR */
Zombie::Zombie()
	:_name("Unknown"), _ptr(NULL)
{
	return ;
}

/** CONSTRUCTOR OVERLOAD*/
Zombie::Zombie(std::string name)
	:_name(name), _ptr(NULL)
{
	return ;
}

/** DESTRUCTOR */
Zombie::~Zombie()
{
	print_name(this->_name);
	std::cout << " deconstructed" << std::endl;
	return ;
}

void	Zombie::eraseZombie(void)
{
	if (this->_ptr != NULL)
		delete this->_ptr;
}

void	Zombie::announce() const
{
	
	print_name(this->_name);
	std::cout << " ";
	std::cout << BRAIN << std::endl;
}

/* --------------------------------- GET | SET --------------------------------- */

void		Zombie::setPtr(Zombie *ptr)
{ 
	this->_ptr = ptr; 
}

std::string	Zombie::getName() const
{ 
	return (this->_name); 
}

void		Zombie::setName(std::string name)
{ 
	this->_name = name;
}


