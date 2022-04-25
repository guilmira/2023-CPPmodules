/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:13:30 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/25 13:15:30 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon1);
		//HumanA();
		~HumanA();
		void attack(void) const;

	private:
		std::string _name;
		Weapon& _weapon_assigned; 
		/* Fundamental entender que aqui tiene que haber una referencia o un puntero. 
		Si pones una clase a modo de variable, se duplicará, y cuando modifiques la clase original
		no modificaá esta, porque no es más que una copia. */

};

#endif