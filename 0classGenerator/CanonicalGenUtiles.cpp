/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalGenUtiles.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:30:02 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 14:14:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canonicalGen.hpp"

std::string toUpperString(std::string & str)
{
	int	i;
	std::string new_str(str);

	i = -1;
	while(str[++i])
		new_str[i] = std::toupper(str[i]);
	return (new_str);
}

/* To append .hpp or .cpp */
std::string	append_extension(const char *extension, std::string &name)
{
	std::string name_with_extension(name);
	return (name_with_extension.append(extension));
}

/*	0 oldclass
	1 oldclass.hpp
	2 oldclass.cpp
	3 OLDCLASS */
void	define_class_names(std::string *old_class_name, std::string *new_class_name)
{

	old_class_name[0] = TEMPLATE;
	std::cout << "Insert new class name\n";
	std::cin >> new_class_name[0];

	old_class_name[1] = append_extension(HPP, old_class_name[0]);
	new_class_name[1] = append_extension(HPP, new_class_name[0]);
	old_class_name[2] = append_extension(CPP, old_class_name[0]);
	new_class_name[2] = append_extension(CPP, new_class_name[0]);
	old_class_name[3] = toUpperString(old_class_name[0]);
	new_class_name[3] = toUpperString(new_class_name[0]);
}