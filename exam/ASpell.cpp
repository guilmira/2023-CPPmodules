

#include "ASpell.hpp"

void		ASpell::launch(ATarget const & target)
		{
			target.getHitbySpell(*this);
		}


