/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:48:42 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 18:19:12 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		AForm *makePresidentialPardonForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		AForm *makeShrubberyCreationForm(std::string target);
		AForm *makeForm(std::string formName, std::string target);
};

#endif
