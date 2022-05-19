/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:48:21 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:10:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

/* LIBRARIES */
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap & operator=(DiamondTrap const &rhs);

		void whoAmI()
		{
			std::cout << "I am " << this->getName();
			std::cout << ". I come from ClapTrap " << this->ClapTrap::getName() << std::endl;
		}

		void attack(std::string const & target)
		{
			this->ScavTrap::attack(target);
		}

		void setName(std::string const name)
		{
			this->_name = name;
		}

	//literal la clave es PONER SU PROPIO GET NAME
	//si no lo pones, usa el get name de Clap y termina sacando el valor de clap.
		const std::string & getName(void) const
		{
			return (this->_name);
		}

		//pendiente ver como hacer bien (y testar el constructor copia y la asignacion
	//tambien ver con jose o con alguien el tema -Wshadow and -Wno-shadow!
	//puedes hacer un pequeño main con swich para testar esta mierda

	private:
		std::string _name;
};

#endif