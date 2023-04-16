/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Caster.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTER_HPP
#define	CASTER_HPP

#include <iostream>
#include <string>
#include <iomanip> //to manipulate output, setting precision etc.
#include <limits> //para los limites de ints etc

/* CLASS DECLARATION. */
class Caster
{
	public:
		Caster();
		Caster(std::string const & name);
		~Caster();
		Caster(Caster const &src);
		Caster & operator=(Caster const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);
		char const &		getX() const;
		void				setX(char const &x);
		double const &		getNb() const;
		void				setNb(double const &nb);

		void	InputtoChar();
		void	InputtoDouble();
		void	displayChar() const;
		void	displayInt() const;
		void	displayFloat() const;
		void	displayDouble() const;
		void	displayAll() const;

		int		flag;
	
	private:
		std::string _name;
		char		_x;
		double		_nb;
};

#endif
