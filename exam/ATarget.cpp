

#include "ATarget.hpp"


	void	ATarget::getHitbySpell(ASpell const & spell) const
		{
			std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
			return ;
		}


