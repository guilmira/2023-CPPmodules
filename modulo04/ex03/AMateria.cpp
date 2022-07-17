/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:04:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/16 14:13:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define END "\033[0m"

static void deep_log(std::string const & type, std::string const & str)
{
	if (!type.compare("ice"))
		std::cout << BLUE;
	else if (!type.compare("cure"))
		std::cout << GREEN;
	else
	{
		std::cout << type << " " << str << std::endl;
		return ;
	}
	std::cout << type << " " << str;
	std::cout << END;
	std::cout << std::endl;
}

AMateria::AMateria()
	: _type("Default")
{
	deep_log(this->_type, "constructed.		| ~ABSTRACT BASE CLASS~");
	return ;
}

AMateria::AMateria(std::string const & type)
	: _type(type)
{
	deep_log(this->_type, "overload constructed.		| ~ABSTRACT BASE CLASS~");
	return ;
}

AMateria::~AMateria()
{
	deep_log(this->_type, "destructed.		| ~ABSTRACT BASE CLASS~");
	return ;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
	deep_log(this->_type, "copy constructed.		| ~ABSTRACT BASE CLASS~");
	return ;
}

AMateria & AMateria::operator=(AMateria const &rhs)
{
	
	deep_log(this->_type, "assgined operator called.		| ~ABSTRACT BASE CLASS~");
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	if (!this->getType().compare(ICE))
		std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << END << std::endl;
	else if (!this->getType().compare(CURE))
		std::cout << GREEN << "* heals " << target.getName() << " wounds *" << END << std::endl;
	else
		deep_log(this->_type, "is a unestable materia. Try Ice/Cure");

}

/* --------------------------------- ICE --------------------------------- */
Ice::Ice() 
	: AMateria(ICE) //explicacion en (*)
{
	deep_log(this->_type, "constructed.");
	return ;
}
/* (*) Cuando instancias la clase ice, se instancia la clase base abstracta: AMateria
Por tanto es algo asi como que por defecto, el constructor de Ice fuese:
Ice::Ice() 
	: AMateria()
Lo que estamos haciendo, es overriding, y que de esta manera, se instancie el atributo _type
con el nombre que realmente queremos.
*/

Ice::~Ice() 
{
	deep_log(this->_type, "destructed.");
	return ;
}

Ice::Ice(Ice const &src)
	: AMateria(src.getType())
{
	*this = src;
	deep_log(this->_type, "copy constructed.");
}

Ice & Ice::operator=(Ice const &rhs)
{
	deep_log(this->_type, "assgined operator called.");
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

AMateria* Ice::clone() const
{
	deep_log(this->_type, "being cloned. Memory allocated.");
	Ice *ice_ptr;
	ice_ptr = new Ice(*this);
	return (ice_ptr);
}

/* --------------------------------- CURE --------------------------------- */

Cure::Cure()
	: AMateria(CURE)
{
	deep_log(this->_type, "constructed.");
	return ;
}

Cure::~Cure()
{
	deep_log(this->_type, "destructed.");
	return ;
}

Cure::Cure(Cure const &src)
	: AMateria(src.getType())
{
	*this = src;
	deep_log(this->_type, "copy constructed.");
}

Cure & Cure::operator=(Cure const &rhs)
{
	deep_log(this->_type, "assgined operator called.");
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

AMateria* Cure::clone() const
{
	deep_log(this->_type, "being cloned. Memory allocated.");
	return (new Cure(*this)); //compacted version
}