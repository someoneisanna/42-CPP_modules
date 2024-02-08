/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:24:13 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/08 18:04:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.hpp"

int main()
{
	Phonebook	p;
	std::string	cmd;

	system("clear");
	std::cout << YELLOW << "*********************************************" << std::endl;
	std::cout << "*                 PHONEBOOK                 *" << std::endl;
	std::cout << "*********************************************" << RESET << std::endl;
	while (1)
	{
		std::cout << "Enter a command (ADD | SEARCH | EXIT): ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			p.add_contact();
		else if (cmd == "SEARCH")
			p.search_contact();
		else
			std::cout << RED << "Invalid command. Try again." << RESET << std::endl;
	}
}
