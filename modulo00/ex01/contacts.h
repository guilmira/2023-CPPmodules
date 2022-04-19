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
#define name 8

#define C1 "add"
#define TYPE_ADD 1
#define C2 "search"
#define TYPE_SEARCH 2
#define C3 "exit"
#define TYPE_EXIT 3
#define MSG "Only three commands are accepted:\nADD, SEARCH and EXIT."

enum e_command
{
	NONE,
	ADD,
	SEARCH,
	EXIT
};

#endif