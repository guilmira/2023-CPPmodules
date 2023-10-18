
#include "Spellbook.hpp"




Spellbook::Spellbook(std::string name, std::string title)
	: _name(name), _title(title)
{
std::cout << _name << ": This looks like another boring day." << std::endl;
	return;
}
Spellbook::~Spellbook()
{
	std::cout << _name << ": My job here is done!" << std::endl;

	for (std::vector<ASpell *>::iterator it = _spells.begin(); it !=  _spells.end(); it++)
	{
		delete *it;
	}
	_spells.clear();
	return;
}
Spellbook::Spellbook(Spellbook const &src)
{
	*this = src;
}
Spellbook & Spellbook::operator=(Spellbook const &lhs)
{
	if (this != &lhs)
	{
		this->_name = lhs._name;
		this->_title = lhs._title;
	}
	return (*this);
}




std::string const & Spellbook::getName() const
{
	return this->_name;
}
std::string const & Spellbook::getTitle() const
{
	return this->_title;
}

void				Spellbook::setTitle(std::string const &title)
{
	this->_title = title;
}

