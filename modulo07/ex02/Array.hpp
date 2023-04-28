/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/07 12:32:42 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>
#include <string>

/* CLASS DECLARATION and DEFINITON (template). */
template<typename T>
class Array
{
	public:
		Array() : _ptr(new T[0]), _size(0) 					{ ilog("Constructed⚪"); } /* Notes ** */
		Array(unsigned int N) : _ptr(new T[N]), _size(N) 	{ ilog("Overload constructed⚪"); }
		~Array()  											{ ilog("-Destructed⭕"); delete [] _ptr; }

		Array(Array const &src) : _ptr(NULL), _size(0)
		{
			*this = src;
			ilog("Copy constructed");
		}

		Array & operator=(Array const &rhs)
		{
			ilog("[=] Assignation operator called");
			if (this != &rhs)
			{
				if (_ptr)
					delete [] _ptr;
				if (getSize() < 0)
					ilog("Assignation failed. Array set to NULL");
				else
					copy_array(this, rhs);
			}
			return (*this);
		}

		T & operator[](size_t iterator) const
		{
			T *ptr;

			ptr = getPtr();
			if (iterator >= getSize())
			{
				throw Array::Bounds();
			}
			else
				return (*(ptr + iterator));
		}

		T *				getPtr() const				 { return (this->_ptr); }
		void			setPtr(T *ptr) 				 { _ptr = ptr; }
		size_t const &	getSize() const				 { return (this->_size); }
		void			setSize(size_t const &size)  { if (size >= 0) {this->_size = size;} }
		void			ilog(const std::string & msg) const { std::cout << "[Class]Array  || " << msg << std::endl; }
		size_t const &	size() const				 { return (this->_size); }

		class Bounds : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("Exception -> Index out of bouds"); }
		};
		
	private:
		T		*_ptr;
		size_t	_size;

		void			copy_array(Array *array, Array const &rhs)
		{
			T	*ptr_source;
			T	*ptr_dest;
			int	array_size;

			ptr_source = rhs.getPtr();
			array_size = rhs.getSize();
			ptr_dest = new T[array_size];
			array->_ptr = ptr_dest;
			array->_size = array_size;
			for (size_t i = 0; i < rhs.getSize(); i++)
				*ptr_dest++ = *ptr_source++;
		}	
};

/* Remember than what is a pure virtual function in the std::exception class.
Therefore, u have to instanciate with the same exact prototype or the compiler will complain */

/* Overloading << */
template <typename T>
std::ostream & operator<<(std::ostream &stream, Array<T> const &rhs)
{
	for (size_t i = 0; i < rhs.getSize(); i++)
		std::cout << rhs[i] << " "; 
	return (stream);
}

/* Notes ** 
Why do we set _ptr(new T[0]), _size(0)  and specially the size is not = 1
We could think like _ptr(new T), _size(1) 
Well here is the deal:
First of all
_ptr(new T[0]) allows us to delete with a: delete[] _ptr;
This one is GENERIC. Otherwise, you should contemplate with an if the case of
a single element to do delete _ptr.

then, the reason for size(0), is that if u create an array by default, and then u use a copy constructor
u will eventually use a new T[getSize()], that will give u one element, which u dont want to have.
an array of one element is VERY different an array with none. Both are pointers, but one has content, the other does not.
*/

#endif
