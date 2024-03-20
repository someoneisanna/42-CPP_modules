/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:16:48 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 13:17:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fraBits = 8;

	public:
		Fixed(void); 						// Default constructor
		Fixed(const Fixed &src); 			// Copy constructor
		Fixed &operator=(const Fixed &rhs); // Assignment operator
		~Fixed(void); 						// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
