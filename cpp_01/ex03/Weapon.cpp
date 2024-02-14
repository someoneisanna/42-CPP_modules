/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:32:11 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 15:51:22 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon(void) {}

std::string const &Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
