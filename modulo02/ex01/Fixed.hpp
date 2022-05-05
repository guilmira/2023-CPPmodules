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
#include <string>
#include <math.h>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &src);
		
		Fixed(const int x);
		Fixed(const float fl);
		
		~Fixed();

		Fixed & operator=(Fixed const &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int					_value;
		static const int	_decimalBits;
};

std::ostream & operator<<(std::ostream &stream, Fixed const &fixedClass);