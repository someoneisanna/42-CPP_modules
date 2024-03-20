/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:58:25 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 13:19:15 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fraBits = 8;

	public:
		Fixed(void);						// Default constructor
		Fixed(const Fixed &src); 			// Copy constructor
		~Fixed(void); 						// Destructor

		Fixed &operator=(const Fixed &src); // Assignment operator

		Fixed(const int n);					// Int constructor
		Fixed(const float n);				// Float constructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif
