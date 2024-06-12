/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:24:11 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/11 14:12:46 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*z2;
	Zombie	*z3;

	Zombie z1("Zombie 1");
	z1.announce();

	z2 = newZombie("Zombie 2");
	z2->announce();
	delete z2;

	randomChump("Zombie 3");

	z3 = newZombie("Zombie 4");
	z3->announce();
	delete z3;

	randomChump("Zombie 5");
}
