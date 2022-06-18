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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>


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

void identify(Base *p)
{
	A *ptr1;
	B *ptr2;
	C *ptr3;

	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	ptr1 = dynamic_cast<A *>(p);
	ptr2 = dynamic_cast<B *>(p);
	ptr3 = dynamic_cast<C *>(p);
	if (ptr1)
		std::cout << "Is type A.\n";
	else if (ptr2)
		std::cout << "Is type B.\n";
	else if (ptr3)
		std::cout << "Is type C.\n";
	else
		std::cout << "Type not found\n";
}

int	main(void)
{
	Base *ptr;

	ptr = generate();
	identify(ptr);
	delete ptr;
	return (0);
}
