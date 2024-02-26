/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 20:00:56 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	/*int *a = new int();
	std::cout << *a << std::endl;
	std::cout << a << std::endl;*/

	// Default constructor - Creates an array of 5 elements initialized to 0

	Array<int> a(5);
	std::cout << "Parametric constructor     'a(5)' : ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;

	// We can fill the array with values
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

	// Fill the array with values
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
	std::cout << "\nERRORS" << std::endl;
	try
	{
		std::cout << "Trying to print an element that is out of bounds 'b[5]'" << std::endl;
		std::cout << b[5];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<int> c;
	Array<int> d(0);
	for (unsigned int i = 0; i < c.size(); i++)
	{
		std::cout << c[i];
		std::cout << d[i];
	}
}
