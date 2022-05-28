/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fighter.hpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fighter.hpp"

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

static void deep_log(std::string const & type, std::string const & str)
{
	std::cout << type << str << std::endl;
}

Fighter::Fighter()
	: _name("Unknown character")
{
	deep_log(this->_name, "constructed.");
	return ;
}
Fighter::Fighter(std::string const & type)
	: _name(type)
{
	deep_log(this->_name, "overload constructed.");
	return ;
}

Fighter::~Fighter()
{
	deep_log(this->_name, "destructed.");
	return ;
}
Fighter::Fighter(Fighter const &src)
{
	*this = src;
	deep_log(this->_name, "copy constructed.");
	return ;
}

Fighter & Fighter::operator=(Fighter const &rhs)
{
	
	deep_log(this->_name, "assgined operator called.");
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}

std::string const & Fighter::getName() const
{
	return (this->_name);
}

void equip(AMateria* m)
{

}

void unequip(int idx)
{

}

void Fighter::use(int idx, ICharacter& target)
{
	std::cout << this->_name << "used on" << target.getName() << std::endl;
}