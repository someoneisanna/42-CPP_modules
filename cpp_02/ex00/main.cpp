/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:17:51 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 10:52:45 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	// Using c=b will call the default and then the assignment operator. If we
	// use Fixed c = b; it will call the copy constructor instead of the default
	c = b;

	// This is the simple one -> Const and Destructor only
	std::cout << a.getRawBits() << std::endl;

	// Copy constructor and assignment operator are called
	std::cout << b.getRawBits() << std::endl;

	// Copy assignment operator is called
	std::cout << c.getRawBits() << std::endl;
}
