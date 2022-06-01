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

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string str);
		Bureaucrat(std::string str, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat & operator=(Bureaucrat const &rhs);

		std::string getName() const;
		int getGrade() const;


		void GradeTooHighException();
		void GradeTooLowException();

	private:
		std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream &stream, Bureaucrat const &rhs);


#endif
