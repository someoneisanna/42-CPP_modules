/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:23:34 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 13:46:33 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors, Destructor & Assignment Overload ------------------------------

Form::Form(void) : _name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form::~Form(void) {}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

// Getters ---------------------------------------------------------------------

std::string	Form::getName() const { return (this->_name); }
bool		Form::getSigned() const { return (this->_signed); }
int			Form::getGradeToSign() const { return (this->_gradeToSign); }
int			Form::getGradeToExecute() const { return (this->_gradeToExecute); }

// Member Functions ------------------------------------------------------------

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

// Exceptions ------------------------------------------------------------------

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low");
}

// Operator Overloads ----------------------------------------------------------

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form: " << src.getName()
		<< " | Signed: " << src.getSigned()
		<< " | Grade to Sign: " << src.getGradeToSign()
		<< " | Grade to Execute: " << src.getGradeToExecute() << std::endl;
	return (o);
}



