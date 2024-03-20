/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:04:54 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:48:10 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor and Destructor --------------------------------------------------

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "> has been destroyed." << std::endl;
}

// Setter ----------------------------------------------------------------------

void Zombie::setName(std::string name)
{
	_name = name;
}

// Member Functions ------------------------------------------------------------

void Zombie::announce(void)
{
	std::cout << _name << ": Braiiiiiiinnnssss..." << std::endl;
}
