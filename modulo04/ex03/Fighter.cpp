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

int Fighter::_max_equipment = MAX_MATERIA + 1;

static void deep_log(std::string const & type, std::string const & str)
{
	std::cout << type << " " << str << std::endl;
}

//constructor initalize pointers on materia_array to NULL.
//also, interface is not INSTACIATED, unlike abstract classes.
Fighter::Fighter()
	: _name("Unknown character"), _current_equipment(0)
{
	for (int i = 0; i < this->_max_equipment; i++)
		this->_materia_pointers_array[i] = NULL;
	deep_log(this->_name, "constructed.");
	return ;
}
Fighter::Fighter(std::string const & type)
	: _name(type), _current_equipment(0)
{
	for (int i = 0; i < this->_max_equipment; i++)
		this->_materia_pointers_array[i] = NULL;
	deep_log(this->_name, "overload constructed.");
	return ;
}

Fighter::~Fighter()
{
	deep_log(this->_name, "object destructed.");
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
		this->_current_equipment = rhs.getCurrentEq();
		for (int i = 0; i < rhs.getCurrentEq(); i++)
		{
			if (this->_materia_pointers_array[i])
				delete this->_materia_pointers_array[i];
			this->_materia_pointers_array[i] = rhs._materia_pointers_array[i]->clone();
		}
	}
	return (*this);
}

std::string const & Fighter::getName() const
{
	return (this->_name);
}

void Fighter::equip(AMateria* m)
{
	if (!m)
	{
		deep_log(m->getType(), "faulty. Not equiped");
		return ;
	}
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materia_pointers_array[i] == m)
		{
			deep_log(m->getType(), "already equiped");
			return ;
		}	
	}
	if (this->_current_equipment > MAX_MATERIA)
		deep_log(this->getName(), "reached equip limit.");
	else
	{
		this->_materia_pointers_array[_current_equipment] = m;
		this->_current_equipment++;
		std::cout << "Class fighter ";
		deep_log(this->getName(), "equips materia.");
	}
}

void Fighter::arrange(int idx)
{
	while (this->_materia_pointers_array[idx + 1] != NULL)
	{
		this->_materia_pointers_array[idx] = this->_materia_pointers_array[idx + 1];
		idx++;
	}
	this->_materia_pointers_array[idx] = NULL;
}

void Fighter::unequip(int idx)
{
	if ((idx >= MAX_MATERIA || idx < 0) || idx + 1 > getCurrentEq())
	{
		deep_log(this->getName(), "does not have equipment in that slot.");
		return ;
	}
	this->_materia_pointers_array[idx] = NULL;
	this->arrange(idx);
	this->_current_equipment--;
	deep_log(this->getName(), "unequiped successfully.");
}

void Fighter::use(int idx, ICharacter& target)
{
	if (idx + 1 > this->getCurrentEq())
	{
		std::cout << "nothing equiped on slot\n";
		return ;
	}
	deep_log(this->getName(), "prepares to cast.");
	if (idx >= 0 && idx < MAX_MATERIA)
		this->_materia_pointers_array[idx]->use(target);
	else
		deep_log(this->getName(), "fails to cast.");
}

int Fighter::getCurrentEq() const
{ 
	return (this->_current_equipment);
}