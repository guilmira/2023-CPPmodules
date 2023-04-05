/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:13:55 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/04 15:32:04 by guilmira         ###   ########.fr       */
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
		void execute_command(void);

		void add_contact(int index);
		void show_contacts(int total) const;
		void exit_contacts(void);
		void single_contact(int total) const;

		int		getValue(void) const;
		void	setValue(int x);

		Contact array_of_contacts[MAX_CONTACTS];
	
	private:
		int _command;
		int _total;
		void _print_string(std::string const &str) const;

};

#endif