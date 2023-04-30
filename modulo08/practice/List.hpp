/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:49 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/28 23:11:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define	LIST_HPP

#include <iostream>
#include <string>

template<typename T>
class Node
{
	public:
		T		content;
		Node<T>	*next;
};

/* CLASS DECLARATION. */
template<typename T>
class List
{
	public:
		List() : _lst(NULL) {};
		/* List(T content)
		{

		} */
		~List() {};
		List(List const &src);
		List & operator=(List const &rhs);

		/* std::string const &	getName() const;
		void				setName(std::string const &name); */
		
		Node<T> *lstnew(T value)
		{	
			Node<T> *new_node;

			new_node = new Node<T>;
			new_node->content = value;
			new_node->next = NULL;
			return (new_node);
		}

		Node<T> *lstlast(List const &lst)
		{
			Node<T> * tmp;
			
			if (!lst._lst)
				return (lst._lst);
			tmp = lst._lst;
			while (tmp->next)
			{
				/* std::cout << tmp->content << std::endl; */
				tmp = tmp->next;
			}
			return (tmp);
		}

		void	push_back(T value)
		{
			Node<T> *last;
			Node<T> *new_node;

			new_node = lstnew(value);
			last = lstlast(*this);
			if (!last)
				this->_lst = new_node;
			else	
				last->next = new_node;
		}
		
	private:
		Node<T> *_lst;

		
		//void	ilog(const std::string & name, const std::string & msg) const;

};



#endif
