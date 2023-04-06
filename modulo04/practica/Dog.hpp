/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define	DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

/* CLASS DECLARATION. */
class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string const & name);
		~Dog();
		Dog(Dog const &src);
		Dog & operator=(Dog const &rhs);

		void makeSound() const
		{
			std::cout << "DOG BARKING:  " << getName() << std::endl;
		}

	private:
		Brain *brain_ptr;

};

#endif
