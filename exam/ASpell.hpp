#pragma once



#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell()
		{
			return;
		}
		ASpell(std::string name, std::string effects)
			: _name(name), _effects(effects)
		{
			return;
		}
		virtual ~ASpell()
		{
			return ;
		}
		ASpell(ASpell const & src)
		{
			*this = src;
		}
		ASpell & operator=(ASpell const &rhs)
		{
			_name = rhs.getName();
			_effects = rhs.getEffects();
			return (*this);
		}

		virtual ASpell *clone() const = 0;

		void		launch(ATarget const & target);
	

		std::string const & getName() const
		{
			return _name;
		}
		std::string const & getEffects() const
		{
			return _effects;
		}

	private:
		std::string _name;
		std::string _effects;
};
