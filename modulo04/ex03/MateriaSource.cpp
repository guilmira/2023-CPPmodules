/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"


int MateriaSource::_max_materia = MAX_MATERIA;

static void log(std::string const & str)
{
	std::cout << str << std::endl;
}

MateriaSource::MateriaSource()
	:_current_materia(0)
{
	for (int i = 0; i < this->_max_materia; i++)
		this->origins[i] = NULL;
	log("MATERIA SOURCE constructed.");
	return ;
}

MateriaSource::~MateriaSource()
{
	log("MATERIA SOURCE destructed.");
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	log("MATERIA SOURCE copy constructed.");
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs)
{
	log("MATERIA SOURCE assigned.");
	if (this != &rhs)
	{
		this->_current_materia = rhs.getCurrentMateria();
		for (int i = 0; i < rhs.getCurrentMateria(); i++)
		{
			if (this->origins[i])
				delete this->origins[i];
			this->origins[i] = rhs.origins[i]->clone();
		}
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria *ptr)
{
	if (_current_materia >= this->_max_materia)
		return ;
	this->origins[this->_current_materia] = ptr;
	this->_current_materia++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::string aux;
	AMateria	*materia_creation;

	materia_creation = NULL;
	for (int i = 0; i < this->_current_materia; i++)
	{
		aux = this->origins[i]->getType();
		if (aux.compare(type) == 0)
		{
			materia_creation = (origins[i])->clone();
		}
		return (materia_creation);
	}
	return (0);
}