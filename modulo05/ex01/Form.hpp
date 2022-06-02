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

#include <iostream>
#include <stdexcept>

class Form
{
	public:
		Form();
		Form(std::string str);
		Form(std::string str, int grade);
		~Form();
		Form(Form const &src);
		Form & operator=(Form const &rhs);


		Form &	operator++();
		Form &	operator--();
		Form		operator++(int);
		Form		operator--(int);

		std::string 	getName() const;
		int				getSigned() const;
		int				getSign() const;
		int				getExe() const;

		//void			setGrade(int x);

	private:
		std::string			_name;
		bool				_signed; //false == 0 always. while (1) 1 == true
		int					_grade_to_sign;
		int					_grade_to_exe;
};

std::ostream & operator<<(std::ostream &stream, Form const &rhs);

#endif
