/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:58:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/16 14:06:56 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void header()
{
	system("clear");
	std::cout << "********************************************************************************" << std::endl;
	std::cout << "*                                  BUREAUCRAT                                  *" << std::endl;
	std::cout << "********************************************************************************" << std::endl;
}

void ask_for_input()
{
	std::string input;
	while (input != "y" && input != "n")
	{
		std::cout << BOLD << "\nDo you want to continue? [y/n]:" << RESET << " ";
		std::cin >> input;
	}
	if (input == "n")
		exit(0);
	else
		header();
}

int main()
{
	header();

	// Test 1 - Constructors ---------------------------------------------------
	{
		Bureaucrat b1;
		std::cout << b1;

		Bureaucrat c0("Juliana", 100);
		std::cout << c0;

		Bureaucrat c1(c0);
		std::cout << c1;

		Bureaucrat c2 = c0;
		std::cout << c2;
	}
	ask_for_input();

	// Test 2 - Constructing With Wrong Grades ---------------------------------
	{
		try
		{
			Bureaucrat b2("Jean", 0);
			std::cout << b2;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Bureaucrat b3("Jean", 151);
			std::cout << b3;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	ask_for_input();

	// Test 3 - Incrementing and Decrementing ----------------------------------
	{
		try
		{
			Bureaucrat b4("Jean", 150);
			std::cout << b4;
			b4.incrementGrade();
			std::cout << b4;
			b4.decrementGrade();
			std::cout << b4;
			b4.incrementGrade();
			std::cout << b4;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Bureaucrat b5("Joe", 2);
			std::cout << b5;
			b5.incrementGrade();
			std::cout << b5;
			b5.incrementGrade();
			std::cout << b5;
			b5.decrementGrade();
			std::cout << b5;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Bureaucrat b6("Jack", 149);
			std::cout << b6;
			b6.decrementGrade();
			std::cout << b6;
			b6.decrementGrade();
			std::cout << b6;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
}
