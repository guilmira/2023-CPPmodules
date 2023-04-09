/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:53:23 by guilmira          #+#    #+#             */
/*   Updated: 2023/04/09 01:57:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* THROWING */

#include <iostream>
#include <fstream>

class MyException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
				return("my own exception");
		}
};

void ft_open(std::ifstream & m)
{
	if (0)
		throw MyException();
	if (0)
		throw std::exception();
	if (0)
		throw std::string("esta");
	if (1)
		throw int(42);
		
	m.open("file_does_not_exist", std::ifstream::in);
	
}

int main(void)
{
	std::ifstream inlet;

	inlet.exceptions(std::ifstream::failbit);
	try
	{
		ft_open(inlet);
	}
	catch (MyException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "⭕OUTPUT⭕" << std::endl;
	}
	/* catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "⭕OUTPUT⭕" << std::endl;
	} */
	catch (std::string &e)
	{
		std::cerr << e << std::endl;
		std::cout << "⭕OUTPUT⭕" << std::endl;
	}
	catch (int &e)
	{
		std::cerr << e << std::endl;
		std::cout << "⭕OUTPUT⭕" << std::endl;
	}
	return (0);
}
