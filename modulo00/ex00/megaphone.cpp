/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 10:25:35 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/17 13:38:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define MOD 32
#define MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

char	ft_caps(char z)
{
	if (z >= 'a' && z<= 'z')
		return (z - MOD);
	return (z);
}

void	print_string(char *str)
{
	int		i;
	char	z;

	i = -1;
	while (str[++i])
	{
		z = ft_caps(str[i]);
		std::cout << z;
	}

}

/** EXECUTION : ./megaphone "string" */
int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		std::cout << MESSAGE;
	while (argv[++i])
		print_string(argv[i]);
	std::cout << std::endl;
	return (0);
}