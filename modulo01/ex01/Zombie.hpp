/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:30:30 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/24 19:23:25 by guilmira         ###   ########.fr       */
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
		void	eraseZombie(void);

		std::string	getName() const { return (this->_name); };
		void	setPtr(Zombie *ptr) { this->_ptr = ptr; };
		void	setName(std::string name) { this->_name = name; };

	private:
		std::string _name;
		Zombie *_ptr;

	
};

#endif