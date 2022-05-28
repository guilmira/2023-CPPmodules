/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>
#define	N 100

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(Brain const &src);
		Brain &operator=(Brain const&rhs);

		std::string const & getIdeas(const int index) const;
		void setIdeas(const int index, std::string const &src);

	private:
		std::string _ideas[N];
};

#endif