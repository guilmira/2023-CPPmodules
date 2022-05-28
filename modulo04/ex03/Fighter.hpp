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

#ifndef FIGHTER_HPP
#define	FIGHTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Fighter : public ICharacter
{
	public:
		Fighter();
		Fighter(std::string const & name);
		~Fighter();
		Fighter(Fighter const &src);
		Fighter & operator=(Fighter const &rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx) = 0;
		void use(int idx, ICharacter& target) = 0;
	
	private:
		std::string _name;
		AMateria *_materia_array;
}


#endif