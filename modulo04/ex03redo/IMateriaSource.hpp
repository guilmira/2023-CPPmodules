/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define	IMATERIASOURCE_HPP

#include <iostream>
#include <string>

#define MAX_SOURCE 4

/* CLASS DECLARATION. */

class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *ptr) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource()
		{
			for (int i = 0; i < MAX_SOURCE; i++)
			{
				_materia_memory[i] = NULL;
			}
		}
		~MateriaSource()
		{
			for (size_t i = 0; i < MAX_SOURCE; i++)
			{
				if (_materia_memory[i])
					delete _materia_memory[i];
			}
			
		}
		MateriaSource(MateriaSource const &src)
		{
			*this = src;
		}
		MateriaSource & operator=(MateriaSource const &rhs)
		{
			if (this != &rhs)
			{
				for (size_t i = 0; i < MAX_SOURCE; i++)
				{
					if (_materia_memory[i])
						delete _materia_memory[i];
					if (rhs._materia_memory[i])
						_materia_memory[i] = createMateria(rhs._materia_memory[i]->getName());
					else
						_materia_memory[i]	= NULL;
				}
				
			}
			return (*this);
		}

		void learnMateria(AMateria *ptr)
		{
			for (size_t i = 0; i < MAX_SOURCE; i++)
			{
				if (!_materia_memory[i])
				{
					_materia_memory[i] = ptr->clone();
					return ;
				}
			}
			std::cout << "Sources memory full" << std::endl;
		}
		AMateria* createMateria(std::string const & type)
		{

			for (size_t i = 0; i < MAX_SOURCE; i++)
			{
				if (_materia_memory[i])
				{

				if (_materia_memory[i]->getName().compare(type) == 0)
					return (_materia_memory[i]->clone());
				}
		
			}
			std::cout << "Could not create." << std::endl;
			return (NULL);
		}


	private:
		AMateria *_materia_memory[MAX_SOURCE];
};



#endif
