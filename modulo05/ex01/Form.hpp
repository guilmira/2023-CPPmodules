/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                             :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string str);
		Form(std::string str, int grade);
		~Form();
		Form(Form const &src);
		Form & operator=(Form const &rhs);

		std::string 	getName() const;
		bool				getSigned() const;
		int				getSign() const;
		int				getExe() const;

		void			beSigned(Bureaucrat const &buro);

	private:
		const std::string			_name;
		bool						_signed; //false == 0 always. while (1) 1 == true
		const int					_grade_to_sign;
		const int					_grade_to_exe;
};

std::ostream & operator<<(std::ostream &stream, Form const &rhs);

#endif
