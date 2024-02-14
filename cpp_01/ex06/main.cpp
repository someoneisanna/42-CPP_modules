/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:46:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 19:01:33 by ataboada         ###   ########.fr       */
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

	std::string input = av[1];
	if (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR")
	{
		std::cout << RED << "[ Probably complaining about insignificant problems ]\n" << RESET;
		return (1);
	}
	else
	{
		Harl h;
		switch (input[0])
		{
			case 'D':
				h.complain("DEBUG");
				// fall through
			case 'I':
				h.complain("INFO");
				// fall through
			case 'W':
				h.complain("WARNING");
				// fall through
			case 'E':
				h.complain("ERROR");
				// fall through
		}
	}
}
