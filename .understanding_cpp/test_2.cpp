/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:43:29 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 09:51:02 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here we undersatand how shadowing of loval variables work in C++.

#include <iostream>

int main()
{
	int apples { 5 };
	{
		std::cout << apples << '\n';
		int apples{ 0 };
		std::cout << apples << '\n';
	}
	std::cout << apples << '\n';
}
