/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/23 16:18:29 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <time.h>
#include <iostream>

/* the only reason a destructor is added is because a dynamic cast requires
a v-table. That where it gets the info, at run time, of the link between classes */
class Base 
{
	public: virtual ~Base() {};
};

class A : public Base {};

class B : public Base
{
	public:
		B() { std::cout << "⭕⭕" << std::endl; };
};

class C : public Base {};

/* srand is seed rand. Using current time. 
Generates a random value between 1 and 9*/
Base *generate(void)
{
	int random;

	srand( time(NULL) );
	random = rand() % 9 + 1;
	if (random < 3)
		return (new A);
	else if ( random < 6)
		return (new B);
	else
		return (new C);
}

/* Instances of A, B, or C have been created. What we have,
is a pointer to BASE class. Using dynamic cast, (that uses v-table, running time info
we can determine what instance is it) */
void identify(Base *p)
{
	A *a_ptr;
	B *b_ptr;
	C *c_ptr;

	a_ptr = dynamic_cast<A *>(p);
	b_ptr = dynamic_cast<B *>(p);
	c_ptr = dynamic_cast<C *>(p);
	if (a_ptr)
		std::cout << "It is an instance of the A class" << std::endl;
	else if (b_ptr)
		std::cout << "⭕⭕" << std::endl;
	else if (c_ptr)
		std::cout << "Is type C.\n";
	else
		std::cout << "Type not found\n";
}

/* a try catch is needed cause a reference cant be NULL */
void identify_by_reference(Base &p)
{
	try
	{
		B &b_reference = dynamic_cast<B &>(p);
		std::cout << "⭕Reference working. Its type B⭕" << std::endl;
		(void) b_reference;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void ft_leaks(void)
{
	system("leaks -q casts");
}

/* Interestingly enough, since the seed is based on time, it seems to 
randomly generate always the same 2 types of instances. */
int	main(void)
{
	Base	*ptr;
	
	ptr = generate();
	identify(ptr);
	delete ptr;
	/* --------------- */
	ptr = generate();
	Base &reference = *ptr;
	identify_by_reference(reference);
	delete ptr;
	return (0);
}
