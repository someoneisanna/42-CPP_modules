/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:47:42 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/16 14:55:28 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors, Destructor & Assignment Overload ------------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
											_target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),
																_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src),
																			_target(src._target)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

// Member Functions ------------------------------------------------------------

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (checkExecution(executor) == false)
		return ;
	std::cout << GREEN << "Drilling noises..." << RESET << std::endl;
	if (rand() % 2)
		std::cout << GREEN << this->_target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << this->_target << " has failed to be robotomized." << RESET << std::endl;
}
