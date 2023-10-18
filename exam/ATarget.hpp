#pragma once


#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget(std::string type)
			: _type(type)
		{
			return;
		}
		virtual ~ATarget()
		{
			return ;
		}

		virtual ATarget *clone() const = 0;

		void	getHitbySpell(ASpell const & spell) const;

		std::string const & getType() const
		{
			return _type;
		}

	private:
		std::string _type;
};

