/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:32 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/02 15:50:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#define NB 1000	
int main(void)
{
	MutantStack<int> mstack;
	
 	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.pop();
	mstack.pop();
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "---------------------------------" << std::endl;
	mstack.push(0);
	mstack.push(20);
	mstack.push(42);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "---------------------------------" << std::endl;
	for (MutantStack<int>::const_iterator c_it = mstack.cbegin(); c_it != mstack.cend(); c_it++)
		std::cout << *c_it << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for (MutantStack<int>::reverse_iterator r_it = mstack.rbegin(); r_it != mstack.rend(); r_it++)
		std::cout << *r_it << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for (MutantStack<int>::const_reverse_iterator cr_it = mstack.crbegin(); cr_it != mstack.crend(); cr_it++)
		std::cout << *cr_it << std::endl;
	return (0);
}

