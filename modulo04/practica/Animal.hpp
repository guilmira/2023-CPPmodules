/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/05 12:47:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION. */
class Animal
{
	public:
		Animal();
		Animal(std::string const & name);
		~Animal();
		Animal(Animal const &src);
		Animal & operator=(Animal const &rhs);

		std::string const &	getName() const;
		void				setName(std::string name);

		virtual void makeSound() const
		{
			std::cout << "Animal sound\n";
		}

	
	protected:
		std::string _instance_name;
};

#endif
