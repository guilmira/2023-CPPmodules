/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/20 10:07:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	//CASTS THEORY
	{
		{//type punning: circunvent type system
		//in c and c++, is managed by the use of pointers
		int i;
		float fl;

		i = 50;

		fl = *(float *) &i; //this is the type punning. 
		/* Step by step: i want to assign a value to fl. And i want to copy exactly what is stored in memory for the int i.
		It will be 32 bits (4bytes) containing the binary for 50, although is actually stored in hexadecimal. Remember 4 bits (16 in decimal) translate to one number in hexa
		3 raws of 8 zeros +  0000 0000 0011 0010     50 in binary
		3 raws of 2 zeros +    0    0    3    2
		so in memory it will look like  32 00 00 00 (left to right because of endian)
		
		So now, step by step:
			1. Get address the i (&i)
			2. Treat it as it would be an address of a float
			3. Derefrence the address and access the value. The value that is on i will be copied and assigned to fl.
		*/
	
		std::cout << "type punning:" << std::endl;
		std::cout << i << std::endl;
		std::cout << fl << std::endl;
		}
	std::cout << "----------------------------------------------" << std::endl;

		/* Simple C casting. You can only cast explicitly.
		int a = 42;
		double b = a; 				no casting. its an implicit conversion, since a double isnt represented at all as an int.
		double b = (double) a; 		casting. now its an explicit converion, by using the c tool of casting.
		This casting is posible because double is of higher herarchy than an int, it has more space available. */
		{

		double a = 5.1;
		double value = (int)a + 5.1; //value of a is gonna be truncated at the casting

		std::cout << "c casting:" << std::endl;
		std::cout << a << std::endl;
		std::cout << value << std::endl;

		//c++ way of casting
		//double val = static_cast<int>(a) ;//value of a is gonna be truncated at the casting
		double val = static_cast<int>(a) + 5.1;//value of a is gonna be truncated at the casting

		std::cout << "c++ static casting:" << std::endl;
		std::cout << a << std::endl;
		std::cout << val << std::endl;


		}

	std::cout << "----------------------------------------------" << std::endl;
		{ //type reinterpretation in c  //very similar to punning.
		//aim of this example: interpret an address to a float, as an address to an int.  THE ADDRESS REMAINS THE SAME
		//in a type_reinterpretation, the bits remain the same. it is NOT a conversion

		float fl = 420.042f;

		void *b = &fl;			//implicit type reinterpretation
		void *c = (void *) &fl;	//explicit type reinterpretation with a cast
		//int *hazard = b;		//demotion, its hazardous. int * its less generic than void *. Remember, float and ints are encoded differently.
		int *hazard2 = (int *) b; //the compiler allows it if done in an explicit way, but its still hazardous

		std::cout << "c type_reinterpretation:" << std::endl;
		std::cout << fl << std::endl;
		std::cout << &fl << std::endl;
		std::cout << c << std::endl;
		std::cout << *hazard2 << std::endl;
		//even the hazard2 is the same address. its just a reinterpretation. the address is not modified.

		


		}
		std::cout << "----------------------------------------------" << std::endl;
		{//an specific case of type reinterpretation, is the type QUALIFIER reinterpretation (make something that isnt const, const, and vicebersa)
		int a = 42;
		int const *b = &a; //implicit promotion, no problem here.
		a = 50; 
		//*b = 80; //error: assignment of read-only location ‘* b’     it is declared as a pointer to a const int.
		std::cout << a << std::endl;
		std::cout << *b << std::endl;

		std::cout << "c type qualifier reinterpretation:" << std::endl;
		const int z = 100;

		int *x = (int *)&z; //explicit DEMOTION. the compiler will not let it be executed if done implicitly.
		*x = 90;
		std::cout << z << std::endl; //undefined behaviour here.
		std::cout << *x << std::endl;
		std::cout << *(&z) << std::endl; //the actual dereference of the address of z has been modified, even though it was declared as const.
		std::cout << x << std::endl;



		}

	std::cout << "----------------------------------------------" << std::endl;

	}

	return (0);
}

//For conver.cpp an example of how to use the function display using pointers to functions.
//using pointer to functions. create an array that stores a pointer to each function, since each has the same return and input (void).
typedef void (Conver::*mytypedef)() const;
void	Conver::display() const
{
	
	/* TEST 1: SINGLE NON MEMBER FUNCTION
	static void (*ptrFunction)(const std::string &);
	ptrFunction = &log;
	ptrFunction("test punteros a funciones"); */

	/* TEST 2: MEMBER FUNCTION. Notice the special syntax and grouping on the call to the function. this-> is needed since its a member ft.
	void (Conver::*ptrFt)() const;
	ptrFt = &Conver::conChar;
	(this->*ptrFt)(); */

	//Test 3: Array created to store the 4 functions and called. Working.
	/* void (Conver::*array[4])() const;
	array[0] = &Conver::conChar;
	array[1] = &Conver::conInt;
	array[2] = &Conver::conFloat;
	array[3] = &Conver::conDouble;

	for (int i = 0; i < 4; i++)
		(this->*array[i])(); */

	//Test 4: using typedef. Array created to store the 4 functions and called. Working.
/* 	mytypedef array[4];

	array[0] = &Conver::conChar;
	array[1] = &Conver::conInt;
	array[2] = &Conver::conFloat;
	array[3] = &Conver::conDouble;

	for (int i = 0; i < 4; i++)
		(this->*array[i])(); */
}