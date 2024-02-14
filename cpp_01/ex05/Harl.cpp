/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:42:05 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 18:40:01 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << GREEN << "[DEBUG]\n" << RESET;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-" << std::endl;
	std::cout << "pickle-special-ketchup burger." << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN << "[INFO]\n" << RESET;
	std::cout << "I cannot believe adding extra bacon cost more money. You" << std::endl;
	std::cout << "You didn’t put enough bacon in my burger. If you did I" << std::endl;
	std::cout << "wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << GREEN << "[WARNING]\n" << RESET;
	std::cout << "I think I deserve to have some extra bacon for free. I've" << std::endl;
	std::cout << "been coming for years whereas you started working here" << std::endl;
	std::cout << "since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << GREEN << "[ERROR]\n" << RESET;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*complaints[i])();
	}
}
