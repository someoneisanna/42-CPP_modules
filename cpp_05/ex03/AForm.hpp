/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AA.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:23:43 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 14:10:50 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		virtual ~AForm();

		AForm &operator=(AForm const &src);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		bool			checkExecution(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif
