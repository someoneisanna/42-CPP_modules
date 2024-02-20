/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:29:25 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:35 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << GREEN << "AAnimal Default Constructor Called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << GREEN << "AAnimal (with TYPE parameter) Constructor Called" << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << GREEN << "AAnimal Copy Constructor Called" << RESET << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << RED << "AAnimal Destructor Called" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &src)
{
	std::cout << "AAnimal Assignment Operator Called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS ---------------------------------------------------------------------

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

// MEMBER FUNCTION -------------------------------------------------------------

void AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound!" << std::endl;
}
