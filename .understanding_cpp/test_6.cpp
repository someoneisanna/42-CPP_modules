/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_6.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:43:40 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 15:45:02 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Here we learn how to use classes in C++ with public members.

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
