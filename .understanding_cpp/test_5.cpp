/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_5.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:19:07 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 10:29:11 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Here we learn how to use the goto statement in C++.

int main()
{
	int x{};
	tryAgain:
		std::cout << "Enter a number between 1 and 5: ";
		std::cin >> x;
	if (x < 1 || x > 5)
		goto tryAgain;
	std::cout << "You entered " << x << std::endl;
}

