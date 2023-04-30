/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:32 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/30 17:49:30 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


void printVector( std::vector<int> const & vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
	Span s(4);


	s.addNumber(3);
	s.addNumber(42);
	s.addNumber(33);

	printVector(s.getVector());
//now they were added to position 4, 5 and 6. Capacity has been probably doubled.

	Span f(s);
	printVector(f.getVector());
	
	std::vector<int> v(f.getVector());
	std::cout << v[5] << std::endl;

	return (0);
}

/* Note 0: trying to use iterators beyond container limits will cause undefined behaviour */

/* Note: why do i use cbegin in std::distance?
because it changes the overload of the function.

I had to use constant iterators, cause im passing to easyfind a container by const ref.
since there is the "promess" that i will not modify the content of the reference" the compailer enforces me to make the iterator const_iterators. Therfore, my return value is a const iterator. Knwoing this, std::distance has to work with const_iterators. and the overload for that, requires that cbegin() gives back a const iterator. So i can use begin(), that gives me a normal iterator.
The "soution" or second option to avoid all of this, is just passing the container by reference and avoiding working with constant things.
In general, is advise to work with constant iterators, but c++ libraries often work with normal iterators. */