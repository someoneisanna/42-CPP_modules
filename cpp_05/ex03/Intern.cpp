/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:48:33 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/17 16:01:48 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors, Destructor & Assignment Overload ------------------------------

Intern::Intern(void) {}

Intern::Intern(const Intern &src) { *this = src; }

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &src) { (void)src; return (*this); }

// Member Functions ------------------------------------------------------------

AForm *Intern::makePresidentialPardonForm(std::string target) { return (new PresidentialPardonForm(target)); }

AForm *Intern::makeRobotomyRequestForm(std::string target) { return (new RobotomyRequestForm(target)); }

AForm *Intern::makeShrubberyCreationForm(std::string target) { return (new ShrubberyCreationForm(target)); }

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm* (Intern::*formList[3])(std::string) =
	{
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};
	std::string formNames[3] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << GREEN << "Intern creates " << formName << " form" << RESET << std::endl;
			return (this->*formList[i])(target);
		}
	}
	std::cout << RED << "Form not found" << RESET << std::endl;
	return (NULL);
}
