/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Esuna.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ESUNA_HPP
#define	ESUNA_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

/* CLASS DECLARATION. */
class Esuna : public AMateria
{
	public:
		Esuna();
		Esuna(std::string const & name);
		~Esuna();
		Esuna(Esuna const &src);
		Esuna & operator=(Esuna const &rhs);

		AMateria *clone() const;
		void use(ICharacter & target);
};

#endif
