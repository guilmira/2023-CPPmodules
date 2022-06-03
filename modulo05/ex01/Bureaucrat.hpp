/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"


class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string str);
		Bureaucrat(std::string str, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat & operator=(Bureaucrat const &rhs);


		Bureaucrat &	operator++();
		Bureaucrat &	operator--();
		Bureaucrat		operator++(int);
		Bureaucrat		operator--(int);

		std::string 	getName() const;
		int				getGrade() const;
		void			setGrade(int x);

		void ft_throw();
		
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

		void signForm(Form const &form) const;

	private:
		std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream &stream, Bureaucrat const &rhs);

#endif
