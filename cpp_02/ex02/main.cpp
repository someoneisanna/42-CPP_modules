/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:59:07 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 14:00:42 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void menu();
void tests_1();
void tests_2(Fixed &a, Fixed &b, Fixed &c, Fixed &d);
void tests_3(Fixed &a, Fixed &b, Fixed &c, Fixed &d);
void tests_4(Fixed &c, Fixed &d);
void tests_5(Fixed &a, Fixed &b, Fixed &c, Fixed &d);

int main(void)
{
	Fixed		a(80);
	Fixed		b(20);
	Fixed		c(50.42f);
	Fixed		d(20.89f);

	system("clear");
	std::string	choice;
	menu();
	while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
	{
		std::cout << "Choose a test: ";
		std::getline(std::cin, choice);
	}
	if (choice == "1")
		tests_1();
	else if (choice == "2")
		tests_2(a, b, c, d);
	else if (choice == "3")
		tests_3(a, b, c, d);
	else if (choice == "4")
		tests_4(c, d);
	else if (choice == "5")
		tests_5(a, b, c, d);
}

void	menu()
{
	system("clear");
	std::cout << "******************************************\n";
	std::cout << "*          OPERATOR OVERLOADING          *\n";
	std::cout << "******************************************\n\n";
	std::cout << "Possible tests for the Fixed class:\n\n";
	std::cout << "1. Subject's main" << std::endl;
	std::cout << "2. Comparison Operators" << std::endl;
	std::cout << "3. Arithmetic Operators" << std::endl;
	std::cout << "4. Increment and Decrement Operators" << std::endl;
	std::cout << "5. Min and Max Functions" << "\n\n";
}

void tests_1()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	system("clear");
	std::cout << "******************************************\n";
	std::cout << "*             SUBJECT'S MAIN             *\n";
	std::cout << "******************************************\n\n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << "\n\n";
}

void tests_2(Fixed &a, Fixed &b, Fixed &c, Fixed &d)
{
	system("clear");
	std::cout << "******************************************\n";
	std::cout << "*          COMPARISON OPERATORS          *\n";
	std::cout << "******************************************\n\n";


	std::cout << "a > b  | " << a << " > " << b << "  | " << (a > b) << std::endl;
	std::cout << "a < b  | " << a << " < " << b << "  | " << (a < b) << std::endl;
	std::cout << "a >= b | " << a << " >= " << b << " | " << (a >= b) << std::endl;
	std::cout << "a <= b | " << a << " <= " << b << " | " << (a <= b) << std::endl;
	std::cout << "a == b | " << a << " == " << b << " | " << (a == b) << std::endl;
	std::cout << "a != b | " << a << " != " << b << " | " << (a != b) << "\n\n";

	std::cout << "c > d  | " << c << " > " << d << "  | " << (c > d) << std::endl;
	std::cout << "c < d  | " << c << " < " << d << "  | " << (c < d) << std::endl;
	std::cout << "c >= d | " << c << " >= " << d << " | " << (c >= d) << std::endl;
	std::cout << "c <= d | " << c << " <= " << d << " | " << (c <= d) << std::endl;
	std::cout << "c == d | " << c << " == " << d << " | " << (c == d) << std::endl;
	std::cout << "c != d | " << c << " != " << d << " | " << (c != d) << "\n\n";
}

void tests_3(Fixed &a, Fixed &b, Fixed &c, Fixed &d)
{
	system("clear");
	std::cout << "******************************************\n";
	std::cout << "*          ARITHMETIC OPERATORS          *\n";
	std::cout << "******************************************\n\n";
	std::cout << "a + b  | " << a << " + " << b << "  | " << (a + b) << std::endl;
	std::cout << "a - b  | " << a << " - " << b << "  | " << (a - b) << std::endl;
	std::cout << "a * b  | " << a << " * " << b << "  | " << (a * b) << std::endl;
	std::cout << "a / b  | " << a << " / " << b << "  | " << (a / b) << "\n\n";

	std::cout << "c + d  | " << c << " + " << d << "  | " << (c + d) << std::endl;
	std::cout << "c - d  | " << c << " - " << d << "  | " << (c - d) << std::endl;
	std::cout << "c * d  | " << c << " * " << d << "  | " << (c * d) << std::endl;
	std::cout << "c / d  | " << c << " / " << d << "  | " << (c / d) << "\n\n";
}

void tests_4(Fixed &c, Fixed &d)
{
	system("clear");
	std::cout << "******************************************\n";
	std::cout << "*        (IN/DE)CREASING OPERATORS       *\n";
	std::cout << "******************************************\n\n";
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << "\n\n";

	std::cout << "c++: " << c++ << std::endl;
	std::cout << "  c: " << c << std::endl;
	std::cout << "++c: " << ++c << std::endl;
	std::cout << "  c: " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "  c: " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "  c: " << c << "\n\n";

	std::cout << "d++: " << d++ << std::endl;
	std::cout << "  d: " << d << std::endl;
	std::cout << "++d: " << ++d << std::endl;
	std::cout << "  d: " << d << std::endl;
	std::cout << "d--: " << d-- << std::endl;
	std::cout << "  d: " << d << std::endl;
	std::cout << "--d: " << --d << std::endl;
	std::cout << "  d: " << d << "\n\n";
}

void tests_5(Fixed &a, Fixed &b, Fixed &c, Fixed &d)
{
	system("clear");
	std::cout << "******************************************\n";
	std::cout << "*          MINIMUM AND MAXIMUM           *\n";
	std::cout << "******************************************\n\n";
	std::cout << "min(a, b) | min(" << a << "," << b << ") | " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) | max(" << a << "," << b << ") | " << Fixed::max(a, b) << "\n\n";
	std::cout << "min(c, d) | min(" << c << "," << d << ") | " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d) | max(" << c << "," << d << ") | " << Fixed::max(c, d) << "\n\n";
}
