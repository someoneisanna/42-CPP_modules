/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:23:34 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 14:09:59 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors, Destructor & Assignment Overload ------------------------------

AForm::AForm(void) : _name("AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm::~AForm(void) {}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

// Getters ---------------------------------------------------------------------

std::string	AForm::getName() const { return (this->_name); }
bool		AForm::getSigned() const { return (this->_signed); }
int			AForm::getGradeToSign() const { return (this->_gradeToSign); }
int			AForm::getGradeToExecute() const { return (this->_gradeToExecute); }

// Member Functions ------------------------------------------------------------

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

bool	AForm::checkExecution(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	return (true);
}

// Exceptions ------------------------------------------------------------------

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade is too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm: Form needs to be signed to be executed.");
}

// Operator Overloads ----------------------------------------------------------

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << "AForm: " << src.getName()
		<< " | Signed: " << src.getSigned()
		<< " | Grade to Sign: " << src.getGradeToSign()
		<< " | Grade to Execute: " << src.getGradeToExecute() << std::endl;
	return (o);
}



