/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:56:28 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 14:06:45 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void header(void)
{
	system("clear");
	std::cout << "***********************************************************\n";
	std::cout << "*                         SCAVTRAP                        *\n";
	std::cout << "***********************************************************\n\n";
}

void continue_message(void)
{
	std::string input;

	while (input != "Y" && input != "N" && input != "y" && input != "n")
	{
		std::cout << "\nDo you want to see another ScavTrap atack? (Y/N): ";
		std::cin >> input;
	}
	std::cout << std::endl;
	if (input == "N" || input == "n")
		exit(0);
	else if (input != "Y" || input != "y")
		header();
}

int main(void)
{
	header();
	{
		ScavTrap c1("Skynet");
		c1.printInfo();
		c1.attack("rebels");
		c1.takeDamage(5);
		c1.beRepaired(5);
		c1.takeDamage(10);
		c1.guardGate();
		c1.attack("rebels");
	}
	continue_message();
	{
		ScavTrap c2("T-800");
		for (int i = 0; i < 11; i++)
			c2.attack("rebels");
	}
	continue_message();
	{
		ScavTrap c3("T-1000");
		c3.takeDamage(10);
		c3.beRepaired(5);
		c3.takeDamage(20);
		c3.attack("rebels");
	}
	continue_message();
	{
		ScavTrap *c4 = new ScavTrap("T-101");
		c4->attack("rebels");
		delete c4;
	}
}
