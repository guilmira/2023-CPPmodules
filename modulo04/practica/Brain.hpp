/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const &src);
		Brain & operator=(Brain const &rhs);

		std::string const &	getIdea(int index) const;
		void				setIdea(int index, std::string idea);

	
	private:
		std::string _ideas[100];
};

#endif
