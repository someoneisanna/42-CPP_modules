/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:21:24 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:49:30 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;

	std::cout << "Memory Adress [Variable]:  " << &s << std::endl;
	std::cout << "Memory Adress [Pointer]:   " << ptr << std::endl;
	std::cout << "Memory Adress [Reference]: " << &ref << std::endl;

	std::cout << std::endl;

	std::cout << "String [Variable]:  " << s << std::endl;
	std::cout << "String [Pointer]:   " << *ptr << std::endl;
	std::cout << "String [Reference]: " << ref << std::endl;
}
