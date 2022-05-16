/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:30:30 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 15:42:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

/* Class DECLARATION. */
class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce() const;

		Zombie* newZombie(std::string name);
		void	eraseZombie(void);

		std::string	getName() const;
		void		setPtr(Zombie *ptr);
		void		setName(std::string name);

	private:
		std::string	_name;
		Zombie		*_ptr;
};

#endif