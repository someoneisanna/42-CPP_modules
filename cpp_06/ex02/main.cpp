/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 09:04:26 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::cout << "---------- IDENTIFY BY POINTER ----------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		std::cout << "Identify: ";
		identify(base);
		delete base;
	}

	std::cout << "---------- IDENTIFY BY REFERENCE ----------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		std::cout << "Identify: ";
		identify(*base);
		delete base;
	}

	std::cout << "------------ IDENTIFY BY NULL -------------" << std::endl;
	Base *base = NULL;
	std::cout << "Identify: ";
	identify(base);
}
