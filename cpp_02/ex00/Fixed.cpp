/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:17:41 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 13:18:43 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// The default constructor is called when an object is declared without
// initialization.
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// The copy constructor is called when an object is initialized from another
// object, as a copy of the original object.
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// The assignment operator is called when an already initialized object is
// assigned a new value from another already initialized object.
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return (*this);
}

// The destructor is called when an object is destroyed (either by going out of
// scope, or by being explicitly deleted).
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Member function that returns the value of the fixed point value.
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

// Member function that sets the value of the fixed point value.
void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
