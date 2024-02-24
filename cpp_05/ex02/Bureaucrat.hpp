/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:27:44 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 17:38:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"

# define RESET	"\033[0m"
# define BOLD	"\033[1m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define PINK	"\033[38;5;206m"
# define ORANGE	"\033[38;2;255;165;0m"
# define CYAN	"\033[36m"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &src);

		std::string const	getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &aform);
		void	executeForm(AForm const &aform) const;

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
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif
