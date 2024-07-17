/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:58:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/17 15:44:08 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void header()
{
	system("clear");
	std::cout << "**************************************************************************************" << std::endl;
	std::cout << "*                                     BUREAUCRAT                                     *" << std::endl;
	std::cout << "**************************************************************************************" << std::endl;
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

	// Test 1 - Exceptions - Presidential---------------------------------------
	{
		Bureaucrat				b1("Arthur Dent", 1);
		Bureaucrat				b2("Ford Prefect", 150);
		PresidentialPardonForm	p1;

		std::cout << b1;
		std::cout << p1;
		try
		{
			//p1.execute(b1);
			b1.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		p1.beSigned(b1);
		std::cout << p1;
		try
		{
			//p1.execute(b1);
			b1.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		std::cout << b2;
		std::cout << p1;
		try
		{
			//p1.execute(b2);
			b2.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	ask_for_input();

	// Test 2 - Exceptions - Shrubbery------------------------------------------
	{
		Bureaucrat				b1("Arthur Dent", 1);
		Bureaucrat				b2("Ford Prefect", 150);
		ShrubberyCreationForm	p1;

		std::cout << b1;
		std::cout << p1;
		try
		{
			//p1.execute(b1);
			b1.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		p1.beSigned(b1);
		std::cout << p1;
		try
		{
			//p1.execute(b1);
			b1.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		std::cout << b2;
		std::cout << p1;
		try
		{
			//p1.execute(b2);
			b2.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	ask_for_input();

	// Test 3 - Exceptions - Robotomy------------------------------------------
	{
		Bureaucrat				b1("Arthur Dent", 1);
		Bureaucrat				b2("Ford Prefect", 150);
		RobotomyRequestForm		p1;

		std::cout << b1;
		std::cout << p1;
		try
		{
			p1.execute(b1);
			b1.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		p1.beSigned(b1);
		std::cout << p1;
		try
		{
			p1.execute(b1);
			b1.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;

		std::cout << b2;
		std::cout << p1;
		try
		{
			p1.execute(b2);
			b2.executeForm(p1);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	ask_for_input();

	// Test 4 - Copies ---------------------------------------------------------
	{
		Bureaucrat				b1("Arthur Dent", 1);
		PresidentialPardonForm	p1;
		PresidentialPardonForm	p2(p1);
		PresidentialPardonForm	p3 = p1;
		RobotomyRequestForm		r1;
		RobotomyRequestForm		r2(r1);
		RobotomyRequestForm		r3 = r1;
		ShrubberyCreationForm	s1;
		ShrubberyCreationForm	s2(s1);
		ShrubberyCreationForm	s3 = s1;

		std::cout << "This is the bureaucrat:" << std::endl;
		std::cout << b1;
		std::cout << BOLD << "\nThese are the tests for the PresidentialPardonForm:" << RESET << std::endl;
		std::cout << p1;
		std::cout << p2;
		std::cout << p3;
		std::cout << BOLD << "\nThese are the tests for the RobotomyRequestForm:" << RESET <<  std::endl;
		std::cout << r1;
		std::cout << r2;
		std::cout << r3;
		std::cout << BOLD << "\nThese are the tests for the ShrubberyCreationForm:" << RESET <<  std::endl;
		std::cout << s1;
		std::cout << s2;
		std::cout << s3;
	}
}
