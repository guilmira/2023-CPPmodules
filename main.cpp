/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:53:23 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/09 18:24:16 by guilmira         ###   ########.fr       */
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

class Parent {};
class Derived : public Parent {};
class None {
	 virtual void ft_what(void)
	 {
		std::cout << "⭕OUTPUT⭕" << std::endl;
	 }
};
int main(void)
{
	
	None z;
	(void)z;
	try
	{
	Parent &ref = dynamic_cast<Parent &>(z);
		/* code */
	std::cout << &ref << std::endl;
	std::cout << "⭕OUTPUT⭕" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		std::cout << e.what() << std::endl;
	}


	int a = 42;

	double b;

	b = static_cast<double>(a);

	int c;
	c = static_cast<double>(b);
	std::cout << b << std::endl;
	std::cout << c << std::endl;





	

	return (0);
}
