/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                  :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define	IMATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#define MAX_MATERIA 4

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &src);
		MateriaSource & operator=(MateriaSource const &rhs);

		void learnMateria(AMateria *ptr);
		AMateria* createMateria(std::string const & type);
		
		int getCurrentMateria() const { return (this->_current_materia); };

	
	private:
		AMateria	*origins[MAX_MATERIA];
		static int	_max_materia;
		int			_current_materia;	

};

#endif