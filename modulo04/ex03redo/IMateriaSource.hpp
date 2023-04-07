/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define	IMATERIASOURCE_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
class IMateriaSource
{
	public:
		IMateriaSource();
		IMateriaSource(std::string const & name);
		~IMateriaSource();
		IMateriaSource(IMateriaSource const &src);
		IMateriaSource & operator=(IMateriaSource const &rhs);

		std::string const &	getName() const;
		void				setName(std::string const &name);

	
	private:
		std::string _name;
};

#endif
