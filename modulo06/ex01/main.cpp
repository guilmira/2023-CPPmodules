/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/23 16:10:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

/* reinterpret_cast does exactly what it says: 
reinterprets the memory as a different type. 
If the bit pattern doesn't match what would be expected 
for that type, the result will differ from the conversion 
performed by static_cast<unsigned>. */


/* Reinterpret cast: it will reinterpret any address, (pointer to int to float), to any other.
The complier does not check. So that means, i could cast int * to void *, which is ok, or float * to double*, not ok. */
//same with pointers to different classes.
//https://stackoverflow.com/questions/37187060/why-is-this-an-error-static-castunsignedi

struct Data
{
	int a;
	int	b;
};


uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data		d;
	Data		*ptr_d;
	uintptr_t	pointer_as_an_int;
	
	d.a = 42;
	d.b = 5;
	ptr_d = &d;
	std::cout << "Original pointer" << std::endl;
	std::cout << ptr_d << std::endl;
	std::cout << "Type punning the pointer to data:" << std::endl;
	std::cout << *reinterpret_cast<int *>(ptr_d) << std::endl;
	std::cout << "How about if we use pointer arithmetic:" << std::endl;
	std::cout << *(reinterpret_cast<int *>(ptr_d) + 1) << std::endl;
	std::cout << "Yet, could we reinterpret to char?:" << std::endl;
	std::cout << *(reinterpret_cast<char *>(ptr_d)) << std::endl;
	std::cout << "Now feel the full strength of c++" << std::endl;
	std::cout << *reinterpret_cast<int *>((reinterpret_cast<char *>(ptr_d) + 4)) << std::endl;
	std::cout << "All right, back to bussiness//pointer serialized" << std::endl;
	pointer_as_an_int = serialize(ptr_d);
	std::cout << pointer_as_an_int << std::endl;
	std::cout << "Value of the pointer deseriaized:" << std::endl;
	std::cout << deserialize(pointer_as_an_int) << std::endl;
	std::cout << "Value is equal to original pointer" << std::endl;
	if (ptr_d == deserialize(pointer_as_an_int))
		std::cout << "Just as expected" << std::endl;
}

/* Check this who lines */
/* std::cout << *ptr_d << std::endl;
std::cout << *reinterpret_cast<int *>(ptr_d) << std::endl; */
/* The first one will not compile. We cant read a dereferenced data struct
because << is not overloaded for that. Yet, in the struct, there is nothing more
than 2 ints, back to back. Thats what it is in memory. So i can type pun it and there we go, we
can read the 42 and treat it just as if it were an int.*/


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