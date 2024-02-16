/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:56:28 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/16 14:40:42 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void header(void)
{
	system("clear");
	std::cout << "***********************************************************\n";
	std::cout << "*                         FRAGTRAP                        *\n";
	std::cout << "***********************************************************\n\n";
}

void continue_message(void)
{
	std::string input;
	std::cout << "\nDo you want to see another FragTrap atack? (Y/N): ";
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
	FragTrap c1("Skynet");
	c1.attack("rebels");
	c1.highFivesGuys();
	c1.takeDamage(5);
	c1.beRepaired(5);
	c1.takeDamage(10);
	c1.attack("rebels");

	continue_message();
	FragTrap c2("T-800");
	for (int i = 0; i < 11; i++)
		c2.attack("rebels");

	continue_message();
	FragTrap c3("T-1000");
	c1.takeDamage(10);
	c1.beRepaired(5);
	c1.takeDamage(20);
	c1.attack("rebels");
}
