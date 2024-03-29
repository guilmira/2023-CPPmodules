/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Canonical.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/09/30 10:31:18 by guilmira         ###   ########.fr       */
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

		std::string const &			getName() const;
		void						setName(std::string const &name);

	private:
		std::string					_name;

		void						ilog(const std::string & name, const std::string & msg) const;

};

#endif