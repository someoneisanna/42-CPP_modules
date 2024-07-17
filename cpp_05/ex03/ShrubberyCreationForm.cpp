/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:59:04 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/17 16:18:16 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors, Destructor & Assignment Overload ------------------------------

ShrubberyCreationForm::ShrubberyCreationForm() :
			AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
			AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
			AForm(src), _target(src._target)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

// Accessors -------------------------------------------------------------------

std::string ShrubberyCreationForm::getTarget() const { return (this->_target); }


// Member Functions ------------------------------------------------------------

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (checkExecution(executor) == false)
		return ;

	std::ofstream tfile;
	tfile.open((_target + "_shrubbery"). c_str());
	tfile << "PRETEND THIS IS A BIG ASCII TREE" << std::endl;
	tfile << "               /\\               " << std::endl;
	tfile << "              /**\\              " << std::endl;
	tfile << "             /@@@@\\             " << std::endl;
	tfile << "            /######\\            " << std::endl;
	tfile << "           /$$$$$$$$\\           " << std::endl;
	tfile << "          /&&&&&&&&&&\\          " << std::endl;
	tfile << "         /~~~~~~~~~~~~\\         " << std::endl;
	tfile << "        /[][][][][][][]\\        " << std::endl;
	tfile << "       /@@@@@@@@@@@@@@@@\\       " << std::endl;
	tfile << "      /##################\\      " << std::endl;
	tfile << "     /$$$$$$$$$$$$$$$$$$$$\\     " << std::endl;
	tfile << "    /&&&&&&&&&&&&&&&&&&&&&&\\    " << std::endl;
	tfile << "   /~~~~~~~~~~~~~~~~~~~~~~~~\\   " << std::endl;
	tfile << "               ||               " << std::endl;
	tfile << "               ||               " << std::endl;
	tfile.close();
	std::cout << GREEN << "ShrubberyCreationForm has been successfully executed by " << executor.getName() << RESET << std::endl;
}

