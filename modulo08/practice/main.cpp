/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/29 19:37:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> v;
	v.push_back(1);	
	v.push_back(3);	
	v.push_back(42);


	
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	
	

}



#include <list>

void	ft_leaks(void)
{
	system("leaks -q array");
}
//atexit(ft_leaks);

/* int main(void)
{
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(42);
	lst.push_back(2);


	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (it == (++lst.begin()))
			it = lst.erase(it);
	}
std::cout << "⭕OUTPUT⭕" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

} */