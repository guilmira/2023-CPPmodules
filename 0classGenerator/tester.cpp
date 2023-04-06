#include "Fighter.hpp"
//clang++ tester.cpp Fighter.cpp
int main(void)
{
	{
		Fighter f;
		Fighter d(f);
	}
	Fighter f("Vi");
}