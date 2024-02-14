/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:04:54 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 10:18:06 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "> has been destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

void Zombie::announce(void)
{
	std::cout << _name << ": Braiiiiiiinnnssss..." << std::endl;
}
