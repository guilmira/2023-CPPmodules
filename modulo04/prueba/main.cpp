/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 13:41:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <string>

int	main(void)
{
	
	Animal cow("Big cow");
	std::string *ptr_str;

	std::cout << "valor de atributo string: " << cow.getType() << std::endl;
	ptr_str = (std::string *) & cow.getType();
	ptr_str->append("CAMBIO");
	std::cout << "valor de atributo string: " << cow.getType() << std::endl;

}



