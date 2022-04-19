/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:13:55 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 15:13:19 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

#ifndef CLASS_NOTEBOOK_HPP
# define CLASS_NOTEBOOK_HPP

/* Class DECLARATION.
Declaración: sinonimo de creación, ie, como será la clase.
Esto es diferente que definir la clase o instanciarla. */
class Notebook
{
	public:
		Notebook();
		~Notebook();

		void read_command(void);
		void execute_command(void); //add , /search,/exit
		void add_contact(int index);
		
		int getValue(void) const;
		void setValue(int x);

		//Contact array_of_contacts;
		Contact array_of_contacts[MAX_CONTACTS];
	
	private:
		int _command;
		int _total;
		void _print_string(std::string const &str);

};

/* int getValue(void) const; 
Ese const, es solo para prototipos dentro de funciones miembro.
Lo que esta diciendo, es que no vas a cambiar nada utilizando this->
i.e. puedes llamar a this->  y mostrarlo, pero no cambiar el contenido.
*/

#endif