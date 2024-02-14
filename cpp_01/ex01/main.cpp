/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:03:50 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/14 10:06:24 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombies;

	zombies = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);

}
