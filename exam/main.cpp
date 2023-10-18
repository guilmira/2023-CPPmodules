
#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"


/* 
1 #pragma once

2 vector de punteros a Aspell. std::vector<Aspell *>  cuidado si te pasan 
el puntero como NULL. actuar solo si hay puntero

3 iteras por el vector. prueba typedef.
delete *it;

4 learn (push-back(spell->clone()))  !!!!!!!!!!!!!!!!!


5 en el destructor, iterar borrandolos.
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ _spells.clear(); !!!!!!!!!!!!!!!!!!!!!!!!!

en el forget
delete *it;

6 it = spell.erase(it)
*/


void ft_leaks(void)
{
  system("leaks a.out");
}

int main()
{
  // atexit(ft_leaks);
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

// richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);

  delete fwoosh;
}