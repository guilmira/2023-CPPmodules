/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>
#include <string>

/* Virtual keyword at Animal is key on destructor.
If a class such as dog, inherits from animal, but then is 
treated as Animal pointer, then only the animal destructor
would be called.  */

class Animal
{
	public:
		Animal();
		Animal(const std::string & str) :_type(str)
		{
			return ;
		}
		virtual ~Animal();
		Animal(Animal const &src);
		Animal & operator=(Animal const &rhs);

		std::string const &	getType(void) const;

	

		void				setType(std::string &src);

		virtual void makeSound(void) const;

		std::string _type;
};

/* Virtual. In the base class, declare function as virtual.
That makes all of its forms virtual, (including the makeSound in the
derived classes. So in cat and dog, its not neccessary to make it virtual
It could be useful for readability.) */

#endif