/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:03:52 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/18 11:27:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
#define ASCII_DIFF 32

void megaphone(const char *str)
{
	int		i;
	char	z;

	z = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			z = str[i] - ASCII_DIFF;
		else
			z = str[i];
		std::cout << str[i];
	}
	
}

/** EXECUTION : ./megaphone "string" */
int main(int argc, const char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		std::cout << MSG;
	else
		while(argv[++i])
			megaphone(argv[i]);
	std::cout << std::endl;
	return (0);
}