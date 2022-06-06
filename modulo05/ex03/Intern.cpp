/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//typedef Form *(*new_type_fn)(std::string const &str);

//new_type_fn Intern::_array[0] = &creator0;

Form *(*Intern::_array[3])(std::string) = { &Intern::creator0, &Intern::creator1, &Intern::creator2 };

static void log(std::string const &str)
{
	std::cout << str << std::endl;
}

Intern::Intern()
{
	log("Intern constructed.");

	this->_name[0] = REQ0;
	this->_name[1] = REQ1;
	this->_name[2] = REQ2;
}

Intern::~Intern()
{
	log("Intern destructed.");
}

Intern::Intern(Intern const &src)
{

	*this = src;
	log("Intern copy constructed.");
}

Intern & Intern::operator=(Intern const &rhs)
{
	log("Intern assigned.");
	if (this != &rhs)
	{
		;//this->_signed = rhs.getStatus();
	}
	return (*this);
}

/* --------------------------------- StaticFuctions --------------------------------- */

/* --------------------------------- FormCreators --------------------------------- */

Form *Intern::creator0(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::creator1(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::creator2(std::string target)
{
	return (new PresidentialPardonForm(target));
}


Form *Intern::makeForm(std::string type, std::string target)
{

	std::string array[3];

	for (int i = 0; i < 3; i++)
	{
		if (!type.compare(this->_name[i]))
		{
			std::cout << "Intern creates " << type << std::endl;
			return (this->_array[i](target));
		}
	}
	throw Intern::NoFormFound();
}

/* --------------------------------- SPECIFIC EXCEPTIONS --------------------------------- */

Intern::NoFormFound::NoFormFound()
{
	std::cout << "INTERN | --No form exception, constructed and ready to be catched.--\n";
}

const char *Intern::NoFormFound::what() const throw()
{
	return ("INTERN | No form found exception thrown.\n"); 
}


