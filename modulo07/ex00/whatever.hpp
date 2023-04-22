/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define	TESTER_HPP

#include <iostream>

template <typename T>
T const &	min(T const & x, T const & y)
{
	return (x < y ? x : y);
}

template <typename T>
T const &	max(T const & x, T const & y)
{
	return (x > y ? x : y);
}


/* CLASS DECLARATION. */
template<typename T>
class	Tester
{
	public:
		Tester(T a, T b) : _a(a), _b(b) {};
		~Tester(void) {};
		
			void	ft_test()
			{
			
				Tester::_nbExamples++;
				T x;
				T y;
				x = _a;
				y = _b;
				std::cout << " 			ejemplo " << Tester::_nbExamples << std::endl;
				std::cout << "x:" << x << std::endl;
				std::cout << "y:" << y << std::endl;
				std::cout << "valor minimo es:" << min<T>(x, y) << std::endl;
				std::cout << "valor maximo es:" << max<T>(x, y) << std::endl;
				std::cout << "swap [template implicito]" << std::endl;
				//swap(x, y);
				std::cout << "after swap" << std::endl;
				std::cout << "x:" << x << std::endl;
				std::cout << "y:" << y << std::endl;
				std::cout << "valor maximo es:" << max<T>(x, y) << std::endl;
				std::cout << "⭕OUTPUT⭕" << std::endl;
			}
		
	private:
		T _a;
		T _b;
		static int	_nbExamples;
		Tester() {};
};

#endif
