/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:24:11 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:42:06 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *z1;
	Zombie *z2;

	z1 = newZombie("Zombie 1");
	z1->announce();
	delete z1;

	randomChump("Zombie 2");

	z2 = newZombie("Zombie 3");
	z2->announce();
	delete z2;

	return (0);
}
