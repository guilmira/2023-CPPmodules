/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:10:18 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/18 11:56:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"



/* Class DECLARATION.
Declaración: sinonimo de creación, ie, como será la clase.
Esto es diferente que definir la clase o instanciarla. */
class Notebook
{
	public:
		Notebook();
		~Notebook();
		int getValue(int x) const;
	private:
		int _x;
		int _y;

};


/* Class DEFINITION. 
* DEFINICIÓN: to code the actual function. 
* The function behaviour within the class is specified. */

/* return is written only for legibility´s sake since
* Constructor and destructors do not have return value.  */

/** CONSTRUCTOR :  */
Notebook::Notebook() 
	: _x(9), _y(4)    //Initializer List. list all members in order, and in brackets, the value.
{
	std::cout << "Constructor called. Notebook class instantiated. ";
	std::cout << "Notebook running." << std::endl;
	return ;
}

/** DESTRUCTOR :  */
Notebook::~Notebook()
{
	std::cout << "Destructor called. Notebook class destroyed." << std::endl;
	return ;
}

int Notebook::getValue(int i) const
{
	if (i == 1)
		return (this->_x);
	else
		return (this->_y);
}

/** EXECUTION : ./contacts
 * This program will run a contact book.
 * ADD, SEARCH and EXIT accepted.									*/
int main(void)
{
	Notebook notebook1;	
	
	std::cout << notebook1.getValue(2) << std::endl;
	return (0);
}