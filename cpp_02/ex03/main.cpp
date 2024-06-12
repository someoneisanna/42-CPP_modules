/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:59:07 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 14:06:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	system("clear");
	std::cout << CYAN << "**************************************************************" << "\n";
	std::cout << "*                            BSP                             *" << "\n";
	std::cout << "**************************************************************" << RESET << "\n\n";

	Point a(1, 5);
	Point b(11, 17);
	Point c(18, 5);

	// This will print the x axis
	for (int i = 0; i <= 20; ++i)
	{
		if (i != 0)
			std::cout << " ";
		if (i < 10)
			std::cout << "0";
		std::cout << i;
	}
	std::cout << std::endl;

	for (int y = 1; y <= 20; ++y)
	{
		// This will print the y axis
		if (y < 10)
			std::cout << "0";
		std::cout << y << " ";

		// This will print the map
		for (int x = 0; x < 20; ++x)
		{
			Point currentPoint(x, y);
			// This will print the triangle
			if (bsp(a, b, c, currentPoint))
				std::cout << MAGENTA << " # " << RESET;
			// This will print the points
			else
				std::cout << " . ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	float x = 0;
	float y = 0;
	std::string input;

	std::cout << BOLD << "Choose a point to check if it's inside the triangle (x y): " << RESET;
	std::cin >> x >> y;
	std::cout << x << " " << y << std::endl;

	Point p(x - 1, y);
	if (bsp(a, b, c, p))
		std::cout << GREEN << "\nThe point is inside the triangle." << RESET << "\n\n";
	else
		std::cout << RED << "\nThe point is outside the triangle." << RESET << "\n\n";

	return 0;
}
