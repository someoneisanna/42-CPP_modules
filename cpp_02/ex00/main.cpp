/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:17:51 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 13:43:16 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{	
	std::cout << "\n----------- First test -----------\n\n";
	{
		// This is the simple one -> Constructor and Destructor only
		Fixed a;

		// Copy constructor and assignment operator are called
		Fixed b(a);
		
		// Copy assignment operator is called
		Fixed c;
		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n----------- Second test -----------\n\n";
	{
		Fixed a;
		Fixed b(a);
		Fixed c;
		c = a;
		
		a.setRawBits(42);
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << "\n----------- Third test -----------\n\n";
	{
		Fixed a;
		a.setRawBits(42);
	
		Fixed b(a);
		Fixed c = a;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
}
