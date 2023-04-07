/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalGen.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:55:06 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 14:15:11 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canonicalGen.hpp"

/* Size_t es literal un typdef para unsigned long en c++. Ayuda con la portabilidad. Usado en todos los prototipos de funciones
que usan contandor, que no será menos que 0. std::string::npos, es la N-position que alcanza cuando no se ha encontrado lo buscado.
Es decir, 0 seria el primer caracter del string, 1, el segundo. N el último. En este sistema 18446744073709551615.
Printealo printeando el contador y comprueba que es lo mismo que ((size_t)-1), que es el -1 casteado a size_t, que da la vuelta hasta el max value.*/
void ft_replace(std::ifstream & inlet, std::ofstream & outlet, std::string *old_class_name, std::string *new_class_name)
{
	std::string	line;
	std::string	new_line;
	size_t		i1;
	size_t		i2;
	size_t		lenght;

	i1 = 0;
	i2 = 0;
	lenght = old_class_name[0].length();
	while (std::getline(inlet, line))
	{
		i1 = line.find(old_class_name[0]);
		i2 = line.find(old_class_name[3]);
		if (i1 != std::string::npos || i2 != std::string::npos)
		{
			while (i1 != std::string::npos)
			{
				new_line = line.replace(i1, lenght, new_class_name[0]);
				i1 = line.find(old_class_name[0]);
			}
			while (i2 != std::string::npos)
			{
				new_line = line.replace(i2, lenght, new_class_name[3]);
				i2 = line.find(old_class_name[3]);
			}
		}
		else
		{
			new_line = line;
		}
		outlet << new_line << std::endl;
	}
	inlet.clear();
	inlet.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/* 	Replace prototype
	std::string& replace(size_t pos, size_t count, const std::string& str); */



void	open_files(std::string old_class, std::string new_class, std::ifstream & inlet_file, std::ofstream & outlet_file)
{
	inlet_file.open(old_class, std::ifstream::in);
	outlet_file.open(new_class, std::ofstream::out);
}

void	define_class_names(std::string *old_class_name, std::string *new_class_name);


int main(void)
{
	
	std::string 	old_class_name[4];
	std::string		new_class_name[4];
	std::ifstream	inlet_file;
	std::ofstream	outlet_file;
	
	while (1)
	{
	define_class_names(old_class_name, new_class_name);
	open_files(old_class_name[1], new_class_name[1], inlet_file, outlet_file);
	ft_replace(inlet_file, outlet_file, old_class_name, new_class_name);
	inlet_file.close();
	outlet_file.close();
	open_files(old_class_name[2], new_class_name[2], inlet_file, outlet_file);
	ft_replace(inlet_file, outlet_file, old_class_name, new_class_name);
	inlet_file.close();
	outlet_file.close();
	}
	return (0);
}

//mejoras, meterle control de errores con try catch.