/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:35:44 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 15:40:18 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

Dog::Dog(void)
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->_brain = NULL;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog Assignment Operator Called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

// MEMBER FUNCTION -------------------------------------------------------------

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
