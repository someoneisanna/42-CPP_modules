/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/25 20:01:56 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	/*int *a = new int();
	std::cout << *a << std::endl;
	std::cout << a << std::endl;*/

	// Constructor with Parameters - Creates an array of 5 elements initialized to 0

	Array<int> a(5);
	
	std::cout << "Parametric constructor     'a(5)' : ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;

	// Filling the array with values
	std::cout << "Fill the array with values 'a'    : ";
	for (unsigned int i = 0; i < a.size(); i++)
	{
		a[i] = i;
		std::cout << a[i];
	}
	std::cout << std::endl;

	// Copy constructor - Creates an array that has the same values as the original
	Array<int> b(a);
	std::cout << "Copy constructor           'b(a)' : ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;

	// Filling the array with values
	std::cout << "Fill the array with values 'b'    : ";
	for (unsigned int i = 0; i < b.size(); i++)
	{
		b[i] = i + 5;
		std::cout << b[i];
	}
	std::cout << std::endl;

	// Assignment operator - Creates an array that has the same values as the original
	b = a;
	std::cout << "Assignment operator        'b = a': ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;

	// Try to print an element that is out of bounds
	try
	{
		std::cout << "Trying to print an element that is out of bounds 'b[5]': ";
		std::cout << b[5];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Constructing an array of complex elements
	Array<std::string> str(3);
	str[0] = "Hello";
	str[1] = "World";
	str[2] = "!";
	std::cout << "Array of strings           'str'  : ";
	for (unsigned int i = 0; i < str.size(); i++)
		std::cout << str[i] << " ";
	std::cout << std::endl;

	// Default constructor - Creates an array of 0 elements
	Array<int> c;
	Array<int> d(0);

	std::cout << "c.size() : " << c.size() << std::endl;
	std::cout << "d.size() : " << d.size() << std::endl;

	// With a const instance, we can only read the array
	const Array<int> e(5);
	
	for (unsigned int i = 0; i < e.size(); i++)
		std::cout << e[i];
	std::cout << std::endl;

	// This should not compile:
	/*for (unsigned int i = 0; i < e.size(); i++)
	{
		e[i] = i;
		std::cout << e[i];
	}
	std::cout << std::endl;*/
}
