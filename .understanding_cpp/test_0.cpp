/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_0.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:33:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/06 16:54:34 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a basic example of a C++ program.
// Compile this program with: c++ -Wall -Wextra -Werror example_0.cpp

#include <iostream>

int main()
{
	// There are new ways to initialize variables in C++
	int a = 0; // This is the most common way to initialize a variable.
	int b(0); // This is a different way to initialize a variable (less preferred).
	int c{0}; // This is another way to initialize a variable.
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of c is: " << c << std::endl;

	// To print something, we use std::cout
	std::cout << "Hello," << " world!" << std::endl;
}


