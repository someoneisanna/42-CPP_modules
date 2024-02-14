/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:55 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 16:03:48 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (_weapon != NULL)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with" << std::endl;
}
