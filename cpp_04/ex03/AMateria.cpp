/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:10:42 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/20 10:00:20 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// CONSTRUCTORS AND DESTRUCTOR -------------------------------------------------

AMateria::AMateria(void) : _type("default")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria (with TYPE parameter) constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria Destructor called" << std::endl;
}

// GETTER ----------------------------------------------------------------------

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

void AMateria::use(ICharacter &target)
{
	(void)target;
}
