/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:13:48 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 16:44:41 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

# define YELLOW "\033[33m"
# define RESET "\033[0m"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src._type)
{
	std::cout << "Cure Copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &src)
{
	std::cout << "Cure Assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << YELLOW << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
