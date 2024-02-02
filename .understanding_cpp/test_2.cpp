/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:43:29 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/01 20:06:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this example, we understand how to create a class and an object in C++.

#include <iostream>

class Dog
{
	public:
	std::string name = "Billy";
	std::string gender = "Male";
	int age = 6;
};

int main()
{
	Dog dogObj;

	std::cout << "Dog name is: " << dogObj.name << std::endl;
	std::cout << "Dog gender is: " << dogObj.gender << std::endl;
	std::cout << "Dog age is: " << dogObj.age << std::endl;

	return 0;
}
