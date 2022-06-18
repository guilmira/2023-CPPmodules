/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

/* reinterpret_cast does exactly what it says: 
reinterprets the memory as a different type. 
If the bit pattern doesn't match what would be expected 
for that type, the result will differ from the conversion 
performed by static_cast<unsigned>. */

struct Data
{
	int x;

	Data(int i) : x(i) {};
	~Data() {};

	private:
		Data() {};

};



/* Reinterpret cast: it will reinterpret any address, (pointer to int to float), to any other.
The complier does not check. So that means, i could cast int * to void *, which is ok, or float * to double*, not ok. */
//same with pointers to different classes.
uintptr_t serialize(Data *ptr)
{
	uintptr_t id;

	id = reinterpret_cast<uintptr_t>(ptr);
	return (id);
}

Data *deserialize(uintptr_t raw)
{
	Data *ptr;

	ptr = NULL;
	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

//https://stackoverflow.com/questions/37187060/why-is-this-an-error-static-castunsignedi



int	main(void)
{
	uintptr_t 		id;
	Data			*first_address;
	Data			*second_address;
	Data			test(1);


	first_address = &test;
	id = serialize(first_address);
	std::cout << first_address << std::endl;
	std::cout << id << std::endl;
	second_address = deserialize(id);

	if (first_address == second_address)
		std::cout << "functions are working\n";
	else
		std::cout << "functions are NOT working\n";
	return (0);
}


/* What reinterpret cast does, its take whatever space in memory, 
that maybe was being treated as an float
and starts to interpret as an int for example.
The difference with a static cast its huge. static cast, for example, will convert the float. Not just treat it as an int.
if you reinterpret cast a float to an int, what you are gonna have is a space of memory, that you think it has an int, 
when in truth it has the bits and code for a float. */
/* int	main(void)
{
	float fl(4.5f);

	int i;
	int j;
	int z;

	i = static_cast<int>(fl); //great, it just converts it.
	//j = reinterpret_cast<int>(fl); //compiler dosent let you reinterpret cast the float to an int
	z = *reinterpret_cast<int*>(&fl); //undefined behaviour (using some type punning)

	std::cout << fl << std::endl;
	std::cout << i << std::endl;
	std::cout << j << std::endl;
	std::cout << z << std::endl;



	return (0);
} */