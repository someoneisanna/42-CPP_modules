/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:46:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 12:55:00 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./harlFilter [DEBUG/INFO/WARNING/ERROR]\n" << RESET;
		return (1);
	}
	
	Harl h;
	int level = -42;
	std::string input = av[1];
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (input == levels[i])
			level = i;
	}
	switch (level)
	{
		case 0:
			h.complain("DEBUG");
		case 1:
			h.complain("INFO");
		case 2:
			h.complain("WARNING");
		case 3:
			h.complain("ERROR");
			break;
		default:
			std::cout << RED << "[ Probably complaining about insignificant problems ]\n" << RESET;
			break;
	}
}
