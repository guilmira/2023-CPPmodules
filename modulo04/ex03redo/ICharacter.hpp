/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define	ICHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

/* CLASS DECLARATION. */
class ICharacter
{
	public:
		public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			//virtual void equip(AMateria *m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;

	
	private:
		std::string _name;
};

#endif
