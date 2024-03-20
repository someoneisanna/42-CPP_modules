/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:43 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:52:37 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor and Destructor --------------------------------------------------

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

// Member Functions ------------------------------------------------------------

void HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
