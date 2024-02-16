/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:56:42 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/16 17:08:20 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

ClapTrap::ClapTrap(void) :	_name("ClapTrap"),
							_hitPoints(10),
							_energyPoints(10),
							_attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :	_name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0)
{
	std::cout << "ClapTrap Name Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap Assignation Operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

void ClapTrap::attack(const std::string& target)
{
	if (canPerformAction() == false)
		return ;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks "<< target
		<< ", causing " << this->_attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (canPerformAction() == false)
		return ;
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
		<< " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (canPerformAction() == false)
		return ;
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount
		<< " points!\n";
}

bool ClapTrap::canPerformAction(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead!\n";
		return (false);
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy points!\n";
		return (false);
	}
	return (true);
}
