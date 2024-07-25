/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:24:49 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/18 15:54:37 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Function Prototypes ---------------------------------------------------------

static bool isChar(std::string input);
static bool isInt(std::string input);
static bool isFloat(std::string input);
static bool isDouble(std::string input);
static bool isPseudo(std::string input);

static void printTable(int type, std::string input);
static void printPseudo(std::string s);
static void printChar(long double n);
static void printInt(long double n);
static void printFloat(long double n);
static void printDouble(long double n);

// Constructor, Destructor, Assignment Operator --------------------------------

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

// Convert Function ------------------------------------------------------------

void ScalarConverter::convert(std::string input)
{
	std::cout << PURPLE << "input: " << input << RESET << std::endl;
	if (isChar(input))
		printTable(CHAR, input);
	else if (isInt(input))
		printTable(INT, input);
	else if (isFloat(input))
		printTable(FLOAT, input);
	else if (isDouble(input))
		printTable(DOUBLE, input);
	else if (isPseudo(input))
		printTable(PSEUDO, input);
	else
		std::cout << RED << "Error: Invalid input" << RESET << std::endl;
}

// Boolean Functions -----------------------------------------------------------

static bool isChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (true);
	return (false);
}

static bool isInt(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			continue;
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

static bool isFloat(std::string input)
{
	int dot_found = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '.')
			dot_found++;
		else if (i == 0 && (input[i] == '+' || input[i] == '-'))
			;
		else if (i == input.length() - 1 && input[i] == 'f')
			;
		else if (!isdigit(input[i]))
			return (false);
	}
	if (dot_found > 1 || input[input.length() - 1] != 'f')
		return (false);
	return (true);
}

static bool isDouble(std::string input)
{
	int dot_found = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '.')
			dot_found++;
		else if (!isdigit(input[i]) && (i != 0 || (input[0] != '+' && input[0] != '-')))
			return (false);
	}
	if (dot_found == 0 || dot_found > 1)
		return (false);
	return (true);
}

static bool isPseudo(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf" ||
		input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

// Print Functions -------------------------------------------------------------

static void	printTable(int type, std::string input)
{
	long double n;
	if (type == PSEUDO)
	{
		printPseudo(input);
		return;
	}
	else if (type == CHAR)
		n = input[0];
	else
		n = std::strtold(input.c_str(), NULL);
	printChar(n);
	printInt(n);
	printFloat(n);
	printDouble(n);
}

static void printPseudo(std::string s)
{
	std::cout << "char:   Impossible" << std::endl;
	std::cout << "int:    Impossible" << std::endl;
	if (s == "-inff" || s == "+inff" || s == "nanf")
		std::cout << "float:  " << s << std::endl;
	else
		std::cout << "float:  " << s << "f" << std::endl;
	if (s == "-inf" || s == "+inf" || s == "nan")
		std::cout << "double: " << s << std::endl;
	else
		std::cout << "double: " << s.substr(0, (s.length() - 1)) << std::endl;
}

static void printChar(long double n)
{
	if (n > std::numeric_limits<char>::max() || n < std::numeric_limits<char>::min())
		std::cout << "char:   Overflow" << std::endl;
	else
	{
		int c = static_cast<int>(n);
		if (isprint(static_cast<char>(c)))
			std::cout << "char:   '" << static_cast<char>(c) << "'" << std::endl;
		else
			std::cout << "char:   Non displayable" << std::endl;
	}
}

static void printInt(long double n)
{
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		std::cout << "int:    Overflow" << std::endl;
	else
	{
		int i = static_cast<int>(n);
		std::cout << "int:    " << i << std::endl;
	}
}

static void printFloat(long double n)
{
	if (n > std::numeric_limits<float>::max() || n < -std::numeric_limits<float>::max())
		std::cout << "float:  Overflow" << std::endl;
	else
	{
		float f = static_cast<float>(n);
		std::cout << "float:  " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

static void printDouble(long double n)
{
	if (n > std::numeric_limits<double>::max() || n < -std::numeric_limits<double>::max())
		std::cout << "double: Overflow" << std::endl;
	else
	{
		double d = static_cast<double>(n);
		std::cout << "double: " << d << std::endl;
	}
}

