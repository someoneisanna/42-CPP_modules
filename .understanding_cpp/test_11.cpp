/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_11.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:09:00 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 17:11:13 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// This is just a simple struct example to see how we can initialize a struct in one line.

struct Employee
{
	std::string f_name;
	std::string l_name;
	int age;
	int phone;
};

int main()
{
	Employee e {"John", "Doe", 25, 1234567890};
	std::cout << "First Name: " << e.f_name << std::endl;
	std::cout << "Last Name: " << e.l_name << std::endl;
	std::cout << "Age: " << e.age << std::endl;
	std::cout << "Phone: " << e.phone << std::endl;
}
