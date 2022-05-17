/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/17 11:55:28 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void ft_leaks(void)
{
	system("leaks karenFilter");
}

static void	execute(int i)
{
	Karen	k1;

	switch (i)
	{
		case 0:
			std::cout << "[ " << O1 << " ]" << std::endl;
			k1.complain(O1);
			std::cout << std::endl;
		
		case 1:
			std::cout << "[ " << O2 << " ]" << std::endl;
			k1.complain(O2);
			std::cout << std::endl;
		
		case 2:
			std::cout << "[ " << O3 << " ]" << std::endl;
			k1.complain(O3);
			std::cout << std::endl;
		
		case 3:
			std::cout << "[ " << O4 << " ]" << std::endl;
			k1.complain(O4);
			std::cout << std::endl;
			break;
	
		default:
			break;
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	std::string					str;
	std::vector<std::string>	options(4);

 	//atexit(ft_leaks);
	if (argc != 2)
		return (0);
	str = argv[1];
	options[0] = O1;
   	options[1] = O2;
	options[2] = O3;
	options[3] = O4;
	for (int i = 0; i < 4; i++)
		if (!str.compare(options[i]))
			execute(i);
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
} 
