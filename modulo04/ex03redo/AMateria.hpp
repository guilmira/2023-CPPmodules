/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define	AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

/* CLASS DECLARATION. */
class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & name);
		virtual ~AMateria();
		AMateria(AMateria const &src);
		AMateria & operator=(AMateria const &rhs);

		std::string const &	getName() const;
		void				setName(std::string &name);


		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter & target);

	
	private:

	protected:
		std::string _name;

};

#endif
