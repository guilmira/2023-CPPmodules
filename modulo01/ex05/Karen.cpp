/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 04:24:01 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/17 11:46:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
	return ;
}

Karen::~Karen()
{
	return ;
}

static void print_str(std::string const &str)
{
	std::cout << str << std::endl;
}

typedef void (Karen::*type_function)();

void Karen::debug(void)
{
	print_str(M1);
}

void Karen::info(void)
{
	print_str(M2);
}

void Karen::warning(void)
{
	print_str(M3);
}

void Karen::error(void)
{
	print_str(M4);
}

void Karen::complain(std::string level)
{
	std::vector<std::string>	options(4);
	std::vector<type_function>	array_of_pointers;
	type_function				ptrFunction_to_execute;

	options[0] = O1;
	options[1] = O2;
	options[2] = O3;
	options[3] = O4;

	array_of_pointers.push_back(&Karen::debug);
	array_of_pointers.push_back(&Karen::info);
	array_of_pointers.push_back(&Karen::warning);
	array_of_pointers.push_back(&Karen::error);

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(options[i]))
		{
			ptrFunction_to_execute = array_of_pointers[i];
			(this->*ptrFunction_to_execute)();
		}
	}
}

/* How its done for a single variable.
void (Karen::*vari)() = &Karen::error;
(this->*vari)(); */

/* typedef int myinteger;
typedef char *mystring;
typedef void (*myfunc)(); */

/* myinteger i;   // is equivalent to    int i;
mystring s;    // is the same as      char *s;
myfunc f;      // compile equally as  void (*f)(); */