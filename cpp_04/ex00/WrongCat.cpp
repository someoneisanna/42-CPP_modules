/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:11:33 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 15:27:38 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// CONSTRUCTOR, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD --------------------

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal(src)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat Assignation Operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

// MEMBER FUNCTION -------------------------------------------------------------

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
