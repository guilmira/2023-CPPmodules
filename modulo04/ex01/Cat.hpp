/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define	CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat const &src);
		Cat & operator=(Cat const &rhs);

		void makeSound(void) const;

//setBrain is not really needed, just a test
		const Brain *getBrain() { return (this->_pointer); };
		void setBrain(Brain *src) 
		{ 	if (this->_pointer)
				delete _pointer;
			this->_pointer = src; 
			};
	
	private:
		Brain *_pointer;
};

#endif