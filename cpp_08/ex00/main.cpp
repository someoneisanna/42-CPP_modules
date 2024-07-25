/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/25 16:08:46 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	// Test with VECTOR container ----------------------------------------------

	std::cout << "\n------------ INT VECTOR container ------------" << std::endl;

	std::vector<int>	c1;
	int					v1 = 3;
	int					v2 = 7;
	char				v3 = 'a';

	for (int i = 0; i < 5; i++)
		c1.push_back(i);

	std::cout << "Vector Values: ";
	for (std::vector<int>::iterator it = c1.begin(); it != c1.end(); it++)
		std::cout << *it << "";
	std::cout << std::endl;

	try
	{
		std::cout << "Trying to find '" << v1 << "' in vector: ";
		easyfind(c1, v1);
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		std::cout << "Trying to find '" << v2 << "' in vector: ";
		easyfind(c1, v2);
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		std::cout << "Trying to find '" << v3 << "' in vector: ";
		easyfind(c1, v3);
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

	// Test with INT LIST container --------------------------------------------

	std::cout << "\n------------- INT LIST container -------------" << std::endl;

	std::list<int>	c2;

	for (int i = 0; i < 5; i++)
		c2.push_back(i);

	std::cout << "List Values: ";
	for (std::list<int>::iterator it = c2.begin(); it != c2.end(); it++)
		std::cout << *it << "";
	std::cout << std::endl;

	try
	{
		std::cout << "Trying to find '" << v1 << "' in list: ";
		easyfind(c2, v1);
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		std::cout << "Trying to find '" << v2 << "' in list: ";
		easyfind(c2, v2);
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		std::cout << "Trying to find '" << v3 << "' in list: ";
		easyfind(c2, v3);
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

	// Test with CHAR LIST container -------------------------------------------

	std::cout << "\n------------- CHAR LIST container ------------" << std::endl;

	std::list<char>	c3;
	char			v4 = 'c';
	char			v5 = 'f';
	int				v6 = 3;

	for (int i = 0; i < 5; i++)
		c3.push_back(i + 97);

	std::cout << "List Values: ";
	for (std::list<char>::iterator it = c3.begin(); it != c3.end(); it++)
		std::cout << *it << "";
	std::cout << std::endl;

	try
	{
		std::cout << "Trying to find '" << v4 << "' in list: ";
		easyfind(c3, v4);
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		std::cout << "Trying to find '" << v5 << "' in list: ";
		easyfind(c3, v5);
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		std::cout << "Trying to find '" << v6 << "' in list: ";
		easyfind(c3, v6);
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}
}
