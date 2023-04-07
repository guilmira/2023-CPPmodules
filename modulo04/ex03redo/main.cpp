/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 15:27:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
//#include "ICharacter.hpp"
#include "Thief.hpp"

void ft_leaks(void)
{
	system("leaks -q materia");
}

int	main(void)
{
	atexit(ft_leaks);
	{

		Thief yitan("Yitán");
	std::cout << "----------------------------------------------" << std::endl;

	
	std::cout << "----------------------------------------------" << std::endl;
	
	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;


	std::cout << "----------------------------------------------" << std::endl;


	std::cout << "----------------------------------------------" << std::endl;
	}
	return (0);
}