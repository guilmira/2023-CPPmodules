#pragma once




#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph()
			 : ASpell("Polymorph", "burn to a crisp")
		{
			return;
		}
		virtual ~Polymorph()
		{
			return ;
		}

		virtual Polymorph *clone() const
		{
			return (new Polymorph(*this));
		}

		void		launch(ATarget const & target)
		{
			target.getHitbySpell(*this);
		}


	private:

};

