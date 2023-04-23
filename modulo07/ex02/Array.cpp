/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:40 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/09 00:30:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

/* CLASS DEFINITION. */

/* ilog = instance log */
/* static void ilog(const std::string & msg)
{
	
	std::cout << "[Class]Array" << msg << std::endl;
} */
/* --------------------------------- CONSTRUCTORS --------------------------------- */
template<typename T>
Array<T>::Array()
	: _ptr(new T), _size(1)
{
	ilog("Constructed⚪");
	return ;
}

template<typename T>
Array<T>::Array(unsigned int N)
	: _ptr(new T[N]), _size(N)
{
	ilog("Overload constructed⚪");
	return ;
}

/* --------------------------------- DESTRUCTOR --------------------------------- */
template<typename T>
Array<T>::~Array()
{
	ilog("-Destructed⭕");
	return ;
}
/* White and red dots means default constructed or destructed */
/* ------------------COPY CONSTRUCTOR AND ASSIGN OVERLOAD OPERATOR------------------ */
/* template<typename T>
Array<T>::Array(Array const &src)
{
	*this = src;
	ilog("Copy constructed");
	return ;
} */
/* Overload actually is previous to copy constructor, since cc uses the assign operator. */
/* template<typename T>
Array & Array<T>::operator=(Array const &rhs)
{
	ilog("[=] Assignation operator called");
	if (this != &rhs)
		this->_ptr = rhs.getPtr();
	return (*this);
} */
/* --------------------------------- GET | SET --------------------------------- */
template<typename T>
T const & Array<T>::getPtr() const
{
	return (this->_ptr);
}

template<typename T>
void Array<T>::setPtr(T const &ptr)
{ 
	this->_ptr = ptr;
}

template<typename T>
int const & Array<T>::getSize() const
{
	return (this->_size);
}

template<typename T>
void Array<T>::setSize(int const &size)
{ 
	this->_ptr = size;
}
/* --------------------------------- METHODS --------------------------------- */

