#include "Fighter.hpp"
//clang++ cTester.cpp Fighter.cpp
int main(void)
{
	{
		Fighter f;
		Fighter d(f);
	}
	Fighter f("Vi");
}