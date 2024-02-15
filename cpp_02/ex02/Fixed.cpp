/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:00:14 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 18:33:57 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR ----------------------------

Fixed::Fixed(void): _rawBits(0) {}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int n)
{
	this->_rawBits = n << this->_fraBits;
}

Fixed::Fixed(const float n)
{
	this->_rawBits = roundf(n * (1 << this->_fraBits));
}

Fixed &Fixed::operator=(const Fixed &src)
{
	this->_rawBits = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {}

// GETTER AND SETTER -----------------------------------------------------------

int		Fixed::getRawBits(void) const { return (this->_rawBits); }
void	Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

// CONVERSION FUNCTIONS --------------------------------------------------------

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

// OVERLOADING OPERATORS - COMPARISON ------------------------------------------

bool	Fixed::operator>(const Fixed &src) const
{
	return (this->_rawBits > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const
{
	return (this->_rawBits < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->_rawBits >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->_rawBits <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->_rawBits == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const
{
	return (this->_rawBits != src.getRawBits());
}

// OVERLOADING OPERATORS - ARITHMETIC ------------------------------------------

Fixed Fixed::operator+(const Fixed &src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

// OVERLOADING OPERATORS - INCREMENT/DECREMENT ---------------------------------

Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_rawBits--;
	return (tmp);
}

// OVERLOADED MEMBER FUNCTIONS -------------------------------------------------

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
