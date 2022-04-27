/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/27 20:34:22 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void ft_leaks(void)
{
	system("leaks karen");
}

int	main(void)
{
	//atexit(ft_leaks);
	Karen k1;
	
	k1.complain(O2);
	return (0);
} 
