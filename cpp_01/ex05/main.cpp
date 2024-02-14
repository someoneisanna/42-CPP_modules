/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:41:58 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 18:42:42 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void menu(void)
{
	std::cout << CYAN << "*********************************************************\n";
	std::cout << "*                   HARL'S COMPLAINTS                   *\n";
	std::cout << "*********************************************************\n" << RESET;
	std::cout << "Complaint Levels:" << std::endl;
	std::cout << "[] DEBUG" << std::endl;
	std::cout << "[] INFO" << std::endl;
	std::cout << "[] WARNING" << std::endl;
	std::cout << "[] ERROR" << std::endl;
	std::cout << CYAN << "*********************************************************\n" << RESET;

}

int main(void)
{
	std::string level;
	std::string input;

	while (1)
	{
		system("clear");
		menu();
		std::cout << BOLD << "Please enter the level of your complaint: " << RESET;
		std::getline(std::cin, level);
		if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR")
		{
			Harl harl;
			std::cout << "\n";
			harl.complain(level);
			std::cout << BOLD << "\nDo you want to file another complaint? (Y/N): " << RESET;
			std::getline(std::cin, input);
			std::cout << "\n";
			if (input == "N")
			{
				std::cout << YELLOW << "Goodbye!\n" << RESET;
				break ;
			}
		}
		else
			std::cout << RED << "Invalid input. Please try again.\n" << RESET;
	}
}
