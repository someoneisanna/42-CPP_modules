/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:58:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 18:21:36 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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

	// Test 1 - Correct Parameters ---------------------------------------------
	{
		Bureaucrat	b1("B1", 1);
		Intern		i1;

		AForm *f1 = i1.makeForm("presidential pardon", "target1");
		delete f1;
	}
	{
		Bureaucrat	b1("B1", 1);
		Intern		i1;

		AForm *f1 = i1.makeForm("shrubbery creation", "target1");
		delete f1;
	}
	{
		Bureaucrat	b1("B1", 1);
		Intern		i1;

		AForm *f1 = i1.makeForm("robotomy request", "target1");
		delete f1;
	}
	ask_for_input();

	// Test 2 - Incorrect Parameters -------------------------------------------
	{
		Bureaucrat	b1("B1", 1);
		Intern		i1;

		AForm *f1 = i1.makeForm("p", "target1");
		delete f1;
	}
	{
		Bureaucrat	b1("B1", 1);
		Intern		i1;

		AForm *f1 = i1.makeForm("s", "target1");
		delete f1;
	}
	{
		Bureaucrat	b1("B1", 1);
		Intern		i1;

		AForm *f1 = i1.makeForm("r", "target1");
		delete f1;
	}
}
