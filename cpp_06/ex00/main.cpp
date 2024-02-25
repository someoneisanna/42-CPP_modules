/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/25 18:03:20 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void header()
{
	system("clear");
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "*                             SCALAR CONVERTER                             *" << std::endl;
	std::cout << "****************************************************************************" << std::endl;
}

void ask_for_input(std::string msg)
{
	std::string input;
	while (input != "y" && input != "n")
	{
		std::cout << BOLD << msg << RESET << " ";
		std::cin >> input;
	}
	if (input == "n")
		exit(0);
	else
		header();
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}

	ScalarConverter::convert(av[1]);
	ask_for_input("\nDo you want to look at some edge cases? [y/n]:");

	// Test 1 - Char -----------------------------------------------------------
	{
		std::cout << "----------------------------------- CHAR -----------------------------------" << std::endl;
		ScalarConverter::convert("a");
		ScalarConverter::convert("A");
		ScalarConverter::convert("*");
		ScalarConverter::convert("#");

		ScalarConverter::convert("+");
		ScalarConverter::convert("-");
		ScalarConverter::convert("ab");
	}
	ask_for_input("\nDo you want to continue? [y/n]:");

	// Test 2 - Int ------------------------------------------------------------
	{
		std::cout << "------------------------------------ INT -----------------------------------" << std::endl;
		ScalarConverter::convert("0");
		ScalarConverter::convert("42");
		ScalarConverter::convert("-42");
		ScalarConverter::convert("+42");

		ScalarConverter::convert("-9999999999999999999999999");
		ScalarConverter::convert("99999999999999999999999999");
		ScalarConverter::convert("9898+989");
		ScalarConverter::convert("9898-989");
	}
	ask_for_input("\nDo you want to continue? [y/n]:");

	// Test 3 - Float ----------------------------------------------------------
	{
		std::cout << "----------------------------------- FLOAT ----------------------------------" << std::endl;
		ScalarConverter::convert("0.0f");
		ScalarConverter::convert("43.2f");
		ScalarConverter::convert("-43.2f");
		ScalarConverter::convert("+43.2f");
		ScalarConverter::convert("42f");

		ScalarConverter::convert("+4.2a");
		ScalarConverter::convert("--4.2f");
		ScalarConverter::convert("42.0a");
		ScalarConverter::convert("42f42f");
		ScalarConverter::convert("4.2.2f");
		ScalarConverter::convert("+42.4.2f");
		ScalarConverter::convert("42.0ff");
	}
	ask_for_input("\nDo you want to continue? [y/n]:");

	// Test 4 - Double ---------------------------------------------------------
	{
		std::cout << "---------------------------------- DOUBLE ----------------------------------" << std::endl;
		ScalarConverter::convert("0.0");
		ScalarConverter::convert("43.2");
		ScalarConverter::convert("-43.2");
		ScalarConverter::convert("+43.2");

		ScalarConverter::convert("+4.2a");
		ScalarConverter::convert("--4.2");
		ScalarConverter::convert("42.0");
	}
	ask_for_input("\nDo you want to continue? [y/n]:");

	// Test 5 - Subject Main Tests ---------------------------------------------
	{
		std::cout << "---------------------------------- SUBJECT ---------------------------------" << std::endl;
		ScalarConverter::convert("0");
		ScalarConverter::convert("nan");
		ScalarConverter::convert("42.0f");
	}
}
