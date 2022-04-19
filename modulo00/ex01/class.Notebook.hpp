/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:13:55 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 18:29:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

#ifndef CLASS_NOTEBOOK_HPP
# define CLASS_NOTEBOOK_HPP

/* Class DECLARATION. */
class Notebook
{
	public:
		Notebook();
		~Notebook();

		void read_command(void);
		void execute_command(void); //add , /search,/exit
		

		void add_contact(int index);
		void show_contacts(int total) const;
		void exit_contacts(void);

		int getValue(void) const;
		void setValue(int x);

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