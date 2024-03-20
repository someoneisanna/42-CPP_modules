/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:32:11 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:51:21 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor and Destructor --------------------------------------------------

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon(void) {}

// Getter and Setter ------------------------------------------------------------

std::string const &Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
