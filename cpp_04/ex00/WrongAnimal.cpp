/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:11:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 15:28:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// CONSTRUCTOR, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD --------------------

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal Assignation Operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

// GETTER ----------------------------------------------------------------------

std::string	WrongAnimal::getType(void) const
{
	return this->_type;
}

// MEMBER FUNCTION -------------------------------------------------------------

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Animal sound!" << std::endl;
}
