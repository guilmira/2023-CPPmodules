/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:34 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/30 14:59:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <algorithm>

/* Funtion 1 to iterate and compare each element.
Using for loop and iterators */
/* template<typename T>
typename T::const_iterator easyfind(T const & container, int element)
{
	for (typename T::const_iterator it = container.cbegin();\
	it != container.cend(); it++ )
	{
		if (element == *it)
			return it;
	}
	throw (std::exception());
} */

/* Funtion 2, using find. More generic, */
template<typename T>
typename T::const_iterator easyfind(T const & container, int element)
{
	typename T::const_iterator result;

	result = std::find(container.cbegin(), container.cend(), element);
	if (result == container.end())
		throw (std::exception());
	else
		return (result);
}