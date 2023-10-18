#pragma once

#include <vector>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Spellbook
{
	public:

		Spellbook(std::string name, std::string title);
		~Spellbook();

		const std::string & getName() const;
		const std::string & getTitle() const;
		void				setTitle(std::string const &title);


		void 				introduce() const
		{
			std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
		}

		void learnSpell(ASpell *spell)
		{
			if (spell)
			{
				for (size_t i = 0; i < this->_spells.size(); i++)
			{
				if (_spells[i]->getName().compare(spell->getName()))
				{
					return;
				}
			}
			_spells.push_back(spell->clone());

			}
		}

typedef std::vector<ASpell *> vecSpell;
/* REVISAR COMPORTAMIENTO DE forget */
		void forgetSpell(std::string spellName)
		{
		

			for (vecSpell::iterator it = _spells.begin(); it != _spells.end(); it ++)
			{
				if (!(((*it)->getName()).compare(spellName)))
				{
					delete *it;
					it = _spells.erase(it);
				}

			}
		}

		ASpell* createSpell(std::string const &spell)
		{
			return new ASpell(spell);
		}



	private:
		Spellbook(Spellbook const &src);
		Spellbook & operator=(Spellbook const &rhs);
		std::string _name;
		std::string	_title;
		std::vector<ASpell *>		_spells;

};

