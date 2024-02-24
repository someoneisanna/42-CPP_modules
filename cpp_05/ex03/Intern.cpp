/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:48:33 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 18:19:09 by ataboada         ###   ########.fr       */
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
	if (formName == "presidential pardon" || formName == "shrubbery creation" || formName == "robotomy request")
	{
		std::cout << GREEN << "Intern creates " << formName << " form" << RESET << std::endl;
		if (formName == "presidential pardon")
			return (makePresidentialPardonForm(target));
		else if (formName == "shrubbery creation")
			return (makeShrubberyCreationForm(target));
		else
			return (makeRobotomyRequestForm(target));
	}
	std::cout << RED << "Form not found" << RESET << std::endl;
	return (NULL);
}
