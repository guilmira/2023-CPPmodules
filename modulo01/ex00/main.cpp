/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:29:31 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 15:42:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define ARRAY_NBR 6

Zombie *newZombie(std::string name);
void randomChump(std::string name);

/* A resolver: si instancias las clases en el stack con nombre
(es decir, inicializadas) y preceden a la reserva en el heap,
deja de haber leaks aunque no uses delete. Probar ejemplo 2** con 4 o 5. */
int	main(void)
{

	/* Ex1: Class declared on stack.
	Destructor is called at the end of scope. */
	{
		Zombie stack_zombie;
		stack_zombie.announce();
	}

	//Try uncommenting  2**
/* 	{
		Zombie stack_zombie("el canceador de leaks");
	} */

	/* Ex4: Class declared on the HEAP.
	Destructor is called at the end of scope.
	The pointer ptr is "destroyed, but not so the content" */
	{
		Zombie *ptr;

		ptr = NULL;
		ptr = new Zombie("example3: sin delete debe dar leaks");
		ptr->announce();
		//Example that 'this' from inside the class and ptr are the same
		/* std::cout << ptr->getter() << std::endl; void 		*getter() {return(this);};
		std::cout << ptr << std::endl; */
		delete ptr;
	}

	/* Ex5: Class declared on the HEAP.
	Destructor is called at the end of scope.
	The pointer ptr is "destroyed, but not so the content" */
	Zombie *tmp;
	{
		Zombie *ptr;
		
		ptr = NULL;
		ptr = new Zombie("example5:Existe fuera del scope.");
		ptr->announce();
		tmp = ptr;
	}
	tmp->announce();
	delete tmp;
	
	/* Ex2: Class declared on stack and initialized.
	Destructor is called at the end of scope. */
	{
		Zombie stack_zombie("example2: stack_zombie");
	}

	/* Ex3: Class declared on stack via function.
	Destructor is called at the end of scope. */
	randomChump("example3: random_chump_zombie");


	/* Ex6: Class declared on the HEAP using function.
	Destructor is called at the end of scope.
	The pointer ptr is "destroyed, but not so the content" */
	{
		Zombie *ptr;

		ptr = NULL;
		ptr = newZombie("Example6: heap via function");
		ptr->announce();
		delete ptr; //se podria usar ptr->eraseZombie();
	}

	/* Ex7: --ARRAY-- of classes declared on the HEAP using function.
	*/
	{
		Zombie *ptr;

		ptr = NULL;
		ptr = new Zombie[ARRAY_NBR];
		ptr[2].announce();
		delete [] ptr;
	}
	return (0);
}