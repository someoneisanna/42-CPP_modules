/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:13:28 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 12:57:16 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

int			check_args(int ac, char **av);
std::string	replace(std::string line, std::string s1, std::string s2);

int main(int ac, char **av)
{
	check_args(ac, av);
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	std::ifstream old_file(av[1]);
	if (!old_file.is_open())
	{
		std::cout << "Error: File not found or could not be opened" << std::endl;
		return (1);
	}
	
	std::ofstream new_file((av[1] + std::string (".replace")).c_str());
	if (!new_file.is_open())
	{
		std::cout << "Error: File could not be created" << std::endl;
		return (1);
	}
	
	if (s1 == s2)
		new_file << old_file.rdbuf();
	else
	{
		std::string line;
		while (std::getline(old_file, line))
			new_file << replace(line, s1, s2) << std::endl;
	}

	old_file.close();
	new_file.close();
}

int check_args(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replacer [filename] [str_to_replace] [str_to_insert]" << std::endl;
		exit (1);
	}
	
	std::string s1 = av[2];
	std::string s2 = av[3];
	if ((s1.length()) == 0 && s2.length() != 0)
	{
		std::cout << "Error: You cannot replace an empty string" << std::endl;
		exit (1);
	}
	return (0);
}

std::string replace(std::string line, std::string s1, std::string s2)
{
	size_t pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
	return (line);
}
