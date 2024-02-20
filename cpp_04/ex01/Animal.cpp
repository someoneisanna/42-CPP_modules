/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:29:25 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:02:17 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

Animal::Animal(void) : _type("Animal")
{
	std::cout << GREEN << "Animal Default Constructor Called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << GREEN << "Animal (with TYPE parameter) Constructor Called" << RESET << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << GREEN << "Animal Copy Constructor Called" << RESET << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << RED << "Animal Destructor Called" << RESET << std::endl;
}

Animal &Animal::operator=(Animal const &animal)
{
	std::cout << "Animal Assignment Operator Called" << std::endl;
	if (this != &animal)
		this->_type = animal._type;
	return (*this);
}

// GETTERS ---------------------------------------------------------------------

std::string	Animal::getType(void) const
{
	return (this->_type);
}

// MEMBER FUNCTION -------------------------------------------------------------

void Animal::makeSound(void) const
{
	std::cout << "Animal sound!" << std::endl;
}
