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
#define MAX_MATERIA 4

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
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		int getCurrentEq() const;
		void arrange(int idx);
	
	private:
		std::string _name;
		AMateria	*_materia_pointers_array[MAX_MATERIA + 1];
		static int	_max_equipment;
		int			_current_equipment;
};

#endif