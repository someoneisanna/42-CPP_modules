/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:09:01 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 17:01:11 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors, Destructor & Assignment Overload ------------------------------

PresidentialPardonForm::PresidentialPardonForm() :
			AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
			AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) :
			AForm(copy), _target(copy._target)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

// Member Functions ------------------------------------------------------------

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (checkExecution(executor) == false)
		return ;
	std::cout << GREEN << this->_target << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
}

