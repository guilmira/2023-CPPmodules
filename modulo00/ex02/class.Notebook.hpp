/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.Notebook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:13:55 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/18 15:21:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		int getValue(void) const;
		void setValue(int x);

	private:
		int _command;

};

#endif