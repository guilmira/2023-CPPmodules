/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Canonical.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANONICAL_HPP
#define	CANONICAL_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
class Canonical
{
	public:
		Canonical();
		Canonical(std::string const & name);
		~Canonical();
		Canonical(Canonical const &src);
		Canonical & operator=(Canonical const &rhs);

		std::string const &	getName() const;
		void				setName(std::string name);

	
	private:
		std::string _instance_name;
};

#endif