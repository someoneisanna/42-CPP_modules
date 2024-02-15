/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:58:25 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 18:22:04 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fraBits = 8;

	public:
		// Constructors and Destructor
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &src);
		~Fixed(void);

		// Getter and Setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Conversion Functions
		float	toFloat(void) const;
		int		toInt(void) const;

		// Overloading Operators - Comparison
		bool	operator>(const Fixed &src) const;
		bool	operator<(const Fixed &src) const;
		bool	operator>=(const Fixed &src) const;
		bool	operator<=(const Fixed &src) const;
		bool	operator==(const Fixed &src) const;
		bool	operator!=(const Fixed &src) const;

		// Overloading Operators - Arithmetic
		Fixed	&operator=(const Fixed &src);
		Fixed	operator+(const Fixed &src) const;
		Fixed	operator-(const Fixed &src) const;
		Fixed	operator*(const Fixed &src) const;
		Fixed	operator/(const Fixed &src) const;

		// Overloading Operators - Increment/Decrement
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		// Overloaded Member Functions
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif
