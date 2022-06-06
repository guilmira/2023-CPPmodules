/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define REQ0 "shrubbery request"
#define REQ1 "robotomy request"
#define REQ2 "presidential request"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &src);
		Intern & operator=(Intern const &rhs);

		Form *makeForm(std::string type, std::string target);
		


		class NoFormFound : public std::exception
		{
			public:
				NoFormFound();
				virtual const char *what() const throw();
		};

		static Form *creator0(std::string target);
		static Form *creator1(std::string target);
		static Form *creator2(std::string target);
	
	private:
		//typedef Form *(*new_type_fn)(std::string const &str); funciona como typedef

		std::string _name[3];
		static Form *(*_array[3])(std::string);
		
		
};

#endif
