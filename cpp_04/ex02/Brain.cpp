/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:50 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 16:25:30 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// CONSTRUCTOR, DESTRUCTOR AND ASSIGNMENT OPERATOR OVERLOAD --------------------

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor Called" << std::endl;
	std::string strs[] = { "Idea 1", "Idea 2", "Idea 3", "Idea 4", "Idea 5" };
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = strs[rand() % 5];
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain &Brain::operator=(Brain const &src)
{
	std::cout << "Brain Assignment Operator Called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

// GETTER ---------------------------------------------------------------------

void Brain::getIdeas(void) const
{
	std::cout << "Brain Ideas: ";
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		std::cout << this->_ideas[i];
		if (i < 99)
			std::cout << ", ";
	}
}
