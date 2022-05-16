/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:30:24 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 15:31:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/** --Allocates zombie class.
 * 1. Alocates using keyword "new".
 * 2. Sets within the class the pointer given by new.
 * 3. Sets the vaiable name. */
Zombie *newZombie(std::string name)
{
	Zombie *new_ptr;
	
	new_ptr = new Zombie;
	(*new_ptr).setPtr(new_ptr);
	new_ptr->setName(name);
	return (new_ptr);
}