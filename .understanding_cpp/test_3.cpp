/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:11:58 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 10:14:27 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Here we learn how to use the switch statement in C++.

int main(void)
{
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	switch (number)
	{
		case 1:
			std::cout << "You entered 1" << std::endl;
			break;
		case 2:
			std::cout << "You entered 2" << std::endl;
			break;
		case 3:
			std::cout << "You entered 3" << std::endl;
			break;
		default:
			std::cout << "You entered a number that is not 1, 2 or 3" << std::endl;
			break;
	}
	return 0;
}
