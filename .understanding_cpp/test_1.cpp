/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:44:48 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/06 17:00:46 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here we understand how cin and cout work in C++.
// CIN: It is used to take input from the user ().
// COUT: It is used to print something to the console.
// We also understand a little more about << and >> operators.

#include <iostream>

int main()
{
	int number;
	std::cout << "Enter a number: "; // without newline (but if you want to add a newline, you can use \n or std::endl)
	std::cin >> number; // takes your input and stores it in the variable 'number'
	std::cout << "You entered: " << number << std::endl; // prints the value of the variable number with a newline

	// you can also get more than one input at a time
	int n1, n2;
	std::cout << "Enter two numbers (separated by whitespace): ";
	std::cin >> n1 >> n2;
	std::cout << "You entered: " << n1 << " and " << n2 << std::endl;
	return 0;
}
