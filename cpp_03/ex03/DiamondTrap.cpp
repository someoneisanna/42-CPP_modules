/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:44:16 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/16 17:45:45 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;

	this->_name = "DiamondTrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap Name Constructor called" << std::endl;

	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	this->ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	this->_name = src._name;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
	std::cout << "DiamondTrap Assignation Operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
		this->ClapTrap::_name = src.ClapTrap::_name;
	}
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

void DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is: " << this->_name
		<< " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::printInfo(void)
{
	std::cout << "\n-------------------------- DIAMOND TRAP INFO -------------------------\n";
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Points: " << this->_hitPoints << std::endl;
	std::cout << "Energy Points: " << this->_energyPoints << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << "ClapTrap Name: " << this->ClapTrap::_name << std::endl;
	std::cout << "----------------------------------------------------------------------\n\n";
}

