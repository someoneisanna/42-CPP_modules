/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:00:14 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 18:28:08 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Mandatory Functions ---------------------------------------------------------

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return *this;
}

// Getters/Setters -------------------------------------------------------------

int		Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

// New Constructors and Functions ----------------------------------------------

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << this->_fraBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(n * (1 << this->_fraBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << this->_fraBits));
}

int		Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fraBits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &src)
{
	out << src.toFloat();
	return (out);
}





