/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:01:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/17 15:16:47 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_H
# define CLASS_CONTACT_H

//#define CATEGORIES {"first name", "last name", "nickname", "phone", "darkest secret"}

/* Class DECLARATION.
Declaración: sinonimo de creación, ie, como será la clase.
Esto es diferente que definir la clase o instanciarla. */
class Contact
{
	public:
		Contact();
		~Contact(void);
		//pondria dos funciones mas. Editar string
		//y show stirng (CONSTANTE).
		void	create_contact(void);
		void	show_fields(void) const;
	private :
		std::string field[5];
		std::string categories[5] = {"first name", "last name", "nickname", "phone", "darkest secret"};
};

#endif