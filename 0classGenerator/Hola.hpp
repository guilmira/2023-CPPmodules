/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hola.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 22:19:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOLA_HPP
#define	HOLA_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
class Hola
{
	public:
		Hola();
		Hola(std::string const & name);
		~Hola();
		Hola(Hola const &src);
		Hola & operator=(Hola const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);


	
	private:
		std::string _name;

		void	ilog(const std::string & name, const std::string & msg) const;

};

#endif
