#pragma once




#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball()
			 : ASpell("Fireball", "burn to a crisp")
		{
			return;
		}
		virtual ~Fireball()
		{
			return ;
		}

		virtual Fireball *clone() const
		{
			return (new Fireball(*this));
		}

		void		launch(ATarget const & target)
		{
			target.getHitbySpell(*this);
		}


	private:

};

