/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/29 17:51:15 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <list>

void	ft_leaks(void)
{
	system("leaks -q array");
}
//atexit(ft_leaks);

int main(void)
{
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(42);
	std::cout << lst.back() << std::endl;
	
	List<std::string> myOwn;

	myOwn.push_back("pana");
	myOwn.push_back("panama");
	myOwn.push_back("panamajack");
	/* Node<int> *i;
	Node<int> *ii; */

	//i = myOwn.lstlast(myOwn)
	std::cout << (myOwn.lstlast(myOwn))->content << std::endl;


}