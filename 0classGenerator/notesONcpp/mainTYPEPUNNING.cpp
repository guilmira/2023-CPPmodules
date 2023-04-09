/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:53:23 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/09 03:27:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* THROWING */

#include <iostream>
#include <fstream>

struct Entity
{
	public:
		int x, y;

	/* pongamos que queremos una funcion para tratar la entidad
	como si fuese un array. Dos opciones */

		int *get_array(void)
		{
			int *new_array = new int[2];
			new_array[0] = this->x;
			new_array[1] = this->y;
			return (new_array);
		}

		int *get_array2(void)
		{
			return ((int *)this);
			//return (&x);
		}

};

int main(void)
{
	Entity entity = {5, 42};


	long *d = (long *) &entity;

	int *array = (int *) &entity;

	int new_y = *(((char *) &entity) + 4);

	std::cout << entity.x << std::endl;	
	std::cout << entity.y << std::endl;	
	std::cout << &entity.x << std::endl;	
	std::cout << &entity.y << std::endl;

	std::cout << *d << std::endl;
	std::cout << array[1] << std::endl;
	std::cout << new_y << std::endl;

	int *ptr_array;
	ptr_array = entity.get_array();
	std::cout << ptr_array[0] << std::endl;
	std::cout << ptr_array[1] << std::endl;

	int *ptr_array2;
	ptr_array2 = entity.get_array2();
	std::cout << ptr_array2[0] << std::endl;
	std::cout << ptr_array2[1] << std::endl;

	return (0);
}
