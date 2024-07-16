/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:58:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/16 14:38:24 by ataboada         ###   ########.fr       */
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
		Form f1("F1", 50, 10);
		Form c2(f1);
		Form c3 = f1;

		std::cout << f1;
		std::cout << c2;
		std::cout << c3;
	}
	ask_for_input();

	// Test 2 - Correct Parameters ---------------------------------------------
	{
		Form		f2("F1", 50, 10);
		Bureaucrat	b1("B1", 50);

		std::cout << b1;
		std::cout << f2;
		f2.beSigned(b1);
		b1.signForm(f2);
		std::cout << f2;
	}
	std::cout << std::endl;

	{
		Form		f3("F3", 50, 10);
		Bureaucrat	b2("B2", 40);

		std::cout << b2;
		std::cout << f3;
		f3.beSigned(b2);
		b2.signForm(f3);
		std::cout << f3;
	}
	ask_for_input();

	// Test 4 - Incorrect Parameters -------------------------------------------
	{
		Form		f4("F4", 50, 10);
		Bureaucrat	b3("B3", 60);

		std::cout << b3;
		std::cout << f4;
		try
		{
			f4.beSigned(b3);
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		b3.signForm(f4);
		std::cout << f4;
	}
}
