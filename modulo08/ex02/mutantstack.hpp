/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define	MUTANTSTACK_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
class Mutantstack
{
	public:
		Mutantstack();
		Mutantstack(std::string const & name);
		~Mutantstack();
		Mutantstack(Mutantstack const &src);
		Mutantstack & operator=(Mutantstack const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

	private:
		std::string _name;

		void	ilog(const std::string & name, const std::string & msg) const;

};

#endif
