/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:15:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/17 19:40:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#define LIMITmax_23bit 2000
#define LIMITmin_23bit -2000
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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;


		int operator>(Fixed const &rhs) const;
		int operator<(Fixed const &rhs) const;
		int operator>=(Fixed const &rhs) const;
		int operator<=(Fixed const &rhs) const;
		int operator==(Fixed const &rhs) const;
		int operator!=(Fixed const &rhs) const;

		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		//prefix (++i) operator.
		Fixed & operator++();
		Fixed & operator--();

		//Overloading the post-fix increment (i++) has a dummy int.
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &			min(Fixed &lhs, Fixed &rhs);
		static Fixed const &	min(Fixed const &lhs, Fixed const &rhs);

		static Fixed &			max(Fixed &lhs, Fixed &rhs);
		static Fixed const &	max(Fixed const &lhs, Fixed const &rhs);
	
	private:
		int					_value;
		static const int	_decimalBits;
};

std::ostream & operator<<(std::ostream &stream, Fixed const &fixedClass);