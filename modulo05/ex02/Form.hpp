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
		Form(std::string str, int grade_sign, int grade_exe);
		virtual ~Form();
		Form(Form const &src);
		Form & operator=(Form const &rhs);

		std::string 	getName() const;
		bool			getStatus() const;
		int				getSign() const;
		int				getExe() const;

		void			beSigned(Bureaucrat const &buro);


		void ft_throw(int grade);

		class GradeTooHighException : public std::exception
		{
		
			public:
				GradeTooHighException();
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				virtual const char *what() const throw();
		};

		virtual void	execute(Bureaucrat const & executor) const = 0;
		bool			execute_check(Bureaucrat const & executor) const;

	protected:
		const std::string			_name;
		bool						_signed;
		const int					_grade_to_sign;
		const int					_grade_to_exe;
};

std::ostream & operator<<(std::ostream &stream, Form const &rhs);

#endif
