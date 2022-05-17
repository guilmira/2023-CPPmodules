/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:34:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/05/17 15:46:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static void	replace(std::string &buffer, std::string const &original, \
 std::string const &replace)
{
	std::size_t	position;
	int	lenght;
	int lenght2;

	lenght = original.length();
	lenght2 = replace.length();
	position = buffer.find(original);
	while ((position != std::string::npos))
	{
		buffer.erase(position, lenght);
		buffer.insert(position, replace);
		position = buffer.find(original, position + lenght2);
	}
	
}	

static void	redo_file(std::ofstream &out_file_object, std::ifstream &in_file_object\
						,std::string s1, std::string s2)
{
	std::string buffer;

	while (std::getline(in_file_object, buffer))
	{
		replace(buffer, s1, s2);
		out_file_object << buffer << std::endl;
	}
}

static void	open_file_output(std::ofstream &out_file_object, char *file_name)
{

	std::string extension(".replace");
	out_file_object.open(file_name + extension, std::ofstream::out); //to open in writing mode
	if (!out_file_object.is_open())
	{
		std::cout << "Error on file output" << std::endl;
		exit(0);
	}
}

static void	open_file_input(std::ifstream &in_file_object, char *file_name)
{
	in_file_object.open(file_name, std::ifstream::in); //to open in read mode. if in argument is omitted, opens read by defaut.
	if (!in_file_object.is_open())
	{
		std::cout << "File does not exist" << std::endl;
		exit(0);
	}
}

void ft_leaks(void)
{
	system("leaks files");
}

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	std::string s1("not empty");
	std::string s2("not empty2");
	std::ifstream in_file_object;
	std::ofstream out_file_object;
		
	if (argc != 4)
	{
		std::cout << "Requires three arguments." << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	open_file_input(in_file_object, argv[1]);
	open_file_output(out_file_object, argv[1]);
	redo_file(out_file_object, in_file_object, s1, s2);
	in_file_object.close();
	out_file_object.close();
	return (0);
} 
