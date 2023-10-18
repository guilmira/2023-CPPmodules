#pragma once



#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh()
			 : ASpell("Fwoosh", "defaut effect")
		{
			return;
		}
		virtual ~Fwoosh()
		{
			return ;
		}

		virtual Fwoosh *clone() const
		{
			return (new Fwoosh(*this));
		}

		void		launch(ATarget const & target)
		{
			target.getHitbySpell(*this);
		}


	private:

};

