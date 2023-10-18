#pragma once



#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy()
			: ATarget("Default")
		{
			return;
		}
		~Dummy()
		{
			return ;
		}

		ATarget *clone() const
		{
			return (new Dummy(*this));
		}

	private:
	
};

