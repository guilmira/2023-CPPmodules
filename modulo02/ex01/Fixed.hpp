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
#include <cmath>

#define LIMITmax_23bit 8388607
#define LIMITmin_23bit -8388608
#define dec_LIMITunsigned_8bit 255
 

#define DECIMAL_BIT_NBR 8

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