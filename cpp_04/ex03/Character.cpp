/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:11:10 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/20 15:45:27 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;208m"
# define PINK "\033[38;5;206m"
# define RESET "\033[0m"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD -------------------

Character::Character(void) : _inventoryCount(0), _name("Default")
{
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_adresses[i] = NULL;
	}
}

Character::Character(std::string const &name) : _inventoryCount(0), _name(name)
{
	std::cout << "Character Name constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_adresses[i] = NULL;
	}
}

Character::Character(Character const &src) : _inventoryCount(0), _name(src._name)
{
	std::cout << "Character Copy constructor called for " << src._name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = src._inventory[i]->clone();
		this->_adresses[i] = src._adresses[i]->clone();
	}
}

Character::~Character(void)
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		if (this->_adresses[i])
			delete (this->_adresses[i]);
	}
}

Character &Character::operator=(Character const &src)
{
	std::cout << "Character Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
			if (this->_adresses[i])
				delete (this->_adresses[i]);
			this->_inventory[i] = src._inventory[i]->clone();
			this->_adresses[i] = src._adresses[i]->clone();
		}
	}
	return (*this);
}

// GETTER ---------------------------------------------------------------------

std::string const &Character::getName(void) const
{
	return (this->_name);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

void Character::equip(AMateria *m)
{
	if (this->_inventoryCount > 3 || !m)
	{
		if (!m)
			std::cout << RED << "Equip Error: Materia is invalid" << RESET << std::endl;
		else
			std::cout << RED << "Equip Error: Inventory is full" << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "Equipped " << m->getType() << " to " << this->_name << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			this->_inventoryCount++;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		if (idx < 0 || idx > 3)
			std::cout << RED << "Unequip Error: Invalid index" << RESET << std::endl;
		else
			std::cout << RED << "Unequip Error: Inventory slot is empty" << RESET << std::endl;
		return;
	}
	std::cout << ORANGE << "Unequipped " << this->_inventory[idx]->getType() << " from " << this->_name << RESET << std::endl;
	this->_adresses[idx] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
	this->_inventoryCount--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		if (idx < 0 || idx > 3)
			std::cout << RED << "Use Error: Invalid index" << RESET << std::endl;
		else
			std::cout << RED << "Use Error: Inventory slot is empty" << RESET << std::endl;
		return;
	}
	std::cout << PINK << "Used " << this->_inventory[idx]->getType() << " on " << target.getName() << RESET << std::endl;
	this->_inventory[idx]->use(target);
}
