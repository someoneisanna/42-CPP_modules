/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:14:39 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/20 11:46:31 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#define BLUE "\033[34m"
#define RESET "\033[0m"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src._type)
{
	std::cout << "Ice Copy constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &src)
{
	std::cout << "Ice Assignment operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
