/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:56:28 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/16 17:50:36 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void header(void)
{
	system("clear");
	std::cout << "**********************************************************************\n";
	std::cout << "*                             DIAMONDTRAP                            *\n";
	std::cout << "**********************************************************************\n\n";
}

void continue_message(std::string message)
{
	std::string input;
	std::cout << message;
	std::cin >> input;
	std::cout << std::endl;
	if (input == "N")
		exit(0);
	else
		header();
}

int main(void)
{
	header();
	DiamondTrap c1("Skynet");
	c1.printInfo();
	c1.whoAmI();
	c1.attack("rebels");
	c1.highFivesGuys();
	c1.takeDamage(5);
	c1.beRepaired(5);
	c1.takeDamage(10);
	c1.attack("rebels");

	continue_message("\nDo you want to see another DiamondTrap atack? (Y/N): ");
	DiamondTrap c2("T-800");
	c2.printInfo();
	for (int i = 0; i < 51; i++)
		c2.attack("rebels");

	continue_message("\nDo you want to see another DiamondTrap atack? (Y/N): ");
	DiamondTrap c3("T-1000");
	c3.printInfo();
	c3.takeDamage(10);
	c3.beRepaired(5);
	c3.takeDamage(20);
	c3.attack("rebels");

	continue_message("\nDo you want to see the destructor messages? (Y/N): ");
}
