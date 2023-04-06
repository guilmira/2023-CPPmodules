/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:18:22 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/06 11:27:28 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
/* 

Para activar el constructor por defecto se podria hacer, utilizzando lo siguiente:
HumanA::HumanA()
	: _instance_name("Default"), weapon_ref( *(new Weapon("Default axe")))
{
	ilog(getName(), "Constructed⚪");
	return ;
}
Claro que luego habria que gestionar el new para no tener leaks
Piensa que estas creando Weapon en dinamico. En el stack creo que no se podria.


*/

HumanA::HumanA(std::string name, Weapon &weapon1)
	: _name(name), _weapon_assigned(weapon1)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with his ";
	std::cout << this->_weapon_assigned.getType();
	std::cout << std::endl;
}

/* SOBRE REFERENCIAS
OBJETOS CON ATRIBUTOS PRIVADO CON REFERENCIA */

/*  "¿Que ha pasado aqui? Parece que no funciona. Guille no ataca con another, ataca con battle axe. En realidad, sucede que la instancia de axe \
	si que ha sido moificada. Sin embargo, lo que Guille tiene equipado, es la instancia LANCE, que nunca fue sustituida, pero si que el nombre de la instancia \
	cambió. La confusión viene de que estás modificando axe, y no ves el cambio porque estas printeando lance. La confirmacion de esto, es printear la clase lance" */
/* int main(void)
{
	Weapon lance("Ultra Glaive");
	Weapon sword("Zweihander");
	HumanA Guille("Guille", lance);
	Guille.attack();
	Weapon axe("Battle axe");
	Guille.setWeapon(axe);
	Guille.attack();
	axe.setName("another");
	Guille.attack();
	//¿que pasa aqui? SOlucionado
	std::cout << "SOLUCION : el nombre sera battle axe. Instancia original modificada::::: " << lance.getName() << std::endl;
	Guille.setWeapon(sword);
	Guille.attack();
	axe.setName("something else");
	Guille.attack();
	std::cout <<"axe:" << axe.getName() << std::endl;
	std::cout <<"sword:" << sword.getName() << std::endl;

} */

/* int main(void)
{
	Weapon	gun("handgun");
	Weapon	knife("switchblade");
	std::cout << "aqui" << std::endl;

	HumanA	h("anon", gun);

	std::cout << "OG handgun ::" << &gun << std::endl;
	std::cout << "og switchblade ::" << &knife << std::endl;
	
	h.attack();
	h.setWeapon(knife);
	h.attack();
	std::cout << "ahora, la clase con puntero " << &gun << " tiene el nombre de " << gun.getName() << std::endl;
	std::cout << "conclusion, la referencia no cambia. Sigue referenciando a la misma instancia de Weapon.\
	 Lo que ha pasado es que le has cambiado el nombre a la instancia" << std::endl;

	std::cout << "magic" << std::endl;
	gun.setName("SM special");
	h.attack();
	return (0);
} */