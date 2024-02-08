/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_4.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:44:57 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 10:25:54 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Here we learn how to use the fallthrough in the switch statement in C++.

int main()
{
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	switch (number)
	{
		case 1:
			std::cout << "You entered 1" << std::endl;
			[[fallthrough]]; // you can use this attribute to stop the warnings
		case 2:
			std::cout << "You entered 2" << std::endl; // (if you don't want to use the attribute)
			// fall through

		case 3:
			std::cout << "You entered 3" << std::endl;
			// fall through
		default:
			std::cout << "You entered a number that is not 1, 2 or 3" << std::endl;
			break;
	}
	return 0;
}

