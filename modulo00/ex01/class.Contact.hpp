/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Contact.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:16:32 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/19 11:35:20 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.h"

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP

class Contact
{
	public:
		Contact();
		Contact(int i);
		~Contact();

		void get_input(void);

	private:
		std::string _data[MAX_FIELDS];
		std::string _fields[MAX_FIELDS];
		int _index;
};

#endif