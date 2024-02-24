/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:27:57 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 12:17:42 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;2;255;165;0m"

// Constructors, Destructor & Assignment Overload ------------------------------

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

// Getters ---------------------------------------------------------------------

std::string const Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

// Member Functions ------------------------------------------------------------

void Bureaucrat::incrementGrade()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	std::cout << GREEN << "Incremented grade" << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	std::cout << ORANGE << "Decremented grade" << RESET << std::endl;
}

// Exceptions ------------------------------------------------------------------

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

// Operator Overloads ----------------------------------------------------------

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (o);
}
