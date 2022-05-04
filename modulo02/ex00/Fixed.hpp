/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:15:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/04 10:11:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &fixed1);
		

		~Fixed();

		Fixed & operator=(Fixed const &rhs);

	private:
		int _entero;
		const static int _decimalBits;
		int _decimal;
		int _width;
		int _bincomma;
};

class Example
{
	public:
		Example();
		Example(Example const &src);
		Example & operator=(Example const &rhs);

		
		~Example();
	private:
		int x;

};