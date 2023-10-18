
#include "Warlock.hpp"




Warlock::Warlock(std::string name, std::string title)
	: _name(name), _title(title)
{
std::cout << _name << ": This looks like another boring day." << std::endl;
	return;
}
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;

	for (std::vector<ASpell *>::iterator it = _spells.begin(); it !=  _spells.end(); it++)
	{
		delete *it;
	}
	_spells.clear();
	return;
}
Warlock::Warlock(Warlock const &src)
{
	*this = src;
}
Warlock & Warlock::operator=(Warlock const &lhs)
{
	if (this != &lhs)
	{
		this->_name = lhs._name;
		this->_title = lhs._title;
	}
	return (*this);
}




std::string const & Warlock::getName() const
{
	return this->_name;
}
std::string const & Warlock::getTitle() const
{
	return this->_title;
}

void				Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

typedef std::vector<ASpell *>::iterator vecIter;
void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	for (vecIter it = _spells.begin(); it != _spells.end(); it++)
	{
		if (!(*it)->getName().compare(spell->getName()))
		{
			return ;
		}
	}
	_spells.push_back(spell->clone());
}

void Warlock::forgetSpell(std::string spellName)
{
	for (vecIter it = _spells.begin(); it != _spells.end(); it++)
	{
		if (!(*it)->getName().compare(spellName))
		{
			delete *it;
			it = _spells.erase(it);
			return ;
		}
	}
}

void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	for (vecIter it = _spells.begin(); it != _spells.end(); it++)
	{
		if (!(*it)->getName().compare(spellName))
		{
			(*it)->launch(target);
			return;
		}
	}
}

ASpell *Spellbook::createSpell(std::string const & spellName)
{
	for(vecIter it = _spells.begin(); it != _spells.end(); it++)
	{
		if (!(*it)->getName().compare(spellName))
		{
			return (*it);
		}
	}
	return (NULL);
}
