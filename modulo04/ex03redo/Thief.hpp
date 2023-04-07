/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thief.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THIEF_HPP
#define	THIEF_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

#define MAX_MATERIA 4

/* CLASS DECLARATION. */
class Thief : public ICharacter
{
	public:
		Thief();
		Thief(std::string const & name);
		~Thief();
		Thief(Thief const &src);
		Thief & operator=(Thief const &rhs);

		std::string	const & getName() const;
		void				setName(std::string const &name);

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	
	private:
		std::string _name;
		AMateria	*inventory[MAX_MATERIA];
};

#endif
