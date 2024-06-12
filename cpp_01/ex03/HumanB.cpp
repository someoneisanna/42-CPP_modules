/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:55 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/11 15:00:09 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor and Destructor --------------------------------------------------

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}
HumanB::~HumanB(void) {}

// Setter ----------------------------------------------------------------------

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

// Member Functions ------------------------------------------------------------

void HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with" << std::endl;
}
