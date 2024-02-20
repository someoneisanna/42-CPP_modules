/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:25:32 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/20 13:57:46 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNATION OPERATOR OVERLOAD ------------------

# define RED "\033[31m"
# define CYAN "\033[36m"
# define PURPLE "\033[35m"
# define RESET "\033[0m"

MateriaSource::MateriaSource(void) : _inventoryCount(0)
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) : _inventoryCount(0)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
	std::cout << "MateriaSource Assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << RED << "Materia is NULL" << RESET << std::endl;
		return ;
	}
	if (this->_inventoryCount > 3)
	{
		if (m)
			delete m;
		std::cout << RED << "Inventory is full" << RESET << std::endl;
		return ;
	}
	this->_inventory[this->_inventoryCount] = m;
	this->_inventoryCount++;
	std::cout << CYAN << "Materia " << m->getType() << " learned" << RESET << std::endl;

}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << PURPLE << "Materia " << type << " created" << RESET << std::endl;
			return (this->_inventory[i]->clone());
		}
	}
	std::cout << RED << "Materia " << type << " not found" << RESET << std::endl;
	return (NULL);
}

