/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0contacts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:09:42 by guilmira          #+#    #+#             */
/*   Updated: 2022/04/17 14:09:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_SYMBOL_H_IS_JUST_STANDARD
# define RANDOM_SYMBOL_H_IS_JUST_STANDARD

/* LIBRARIES */
#include <iostream>
#include <iomanip>
#include <string>

/* CONSTANTS */
#define MAX_CONTACTS 8
#define MAX_FIELDS 5

/* CLASS DEFINITIONS */
#include "class.Contact.hpp"
#include "class.Notebook.hpp"

/* FIELDS */
#define F0 "index"
#define F1 "first name"
#define F2 "last name" 
#define F3 "nickname" 
#define F4 "phone"
#define F5 "darkest secret"

enum e_command
{
	NONE,
	ADD,
	SEARCH,
	EXIT
};

#endif