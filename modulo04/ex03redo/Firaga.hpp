/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Firaga.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRAGA_HPP
#define	FIRAGA_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

/* CLASS DECLARATION. */
class Firaga : public AMateria
{
	public:
		Firaga();
		Firaga(std::string const & name);
		~Firaga();
		Firaga(Firaga const &src);
		Firaga & operator=(Firaga const &rhs);

		AMateria *clone() const;
		void use(ICharacter & target);
};

#endif
