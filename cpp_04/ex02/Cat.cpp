/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:35:38 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:50 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

Cat::Cat(void)
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal(src)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->_brain = NULL;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "Cat Assignment Operator Called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// MEMBER FUNCTION -------------------------------------------------------------

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
