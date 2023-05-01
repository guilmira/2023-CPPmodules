/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:17:32 by guilmira          #+#    #+#             */
/*   Updated: 2023/05/01 18:41:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <stack>
#define NB 1000	
int main(void)
{

	std::stack<int> stk;

	stk.push(1);
	stk.push(2);
	stk.push(42);

	std::cout << stk.top() << std::endl;
	return (0);
}

