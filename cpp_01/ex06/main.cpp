/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:46:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 13:30:55 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./harlFilter [DEBUG/INFO/WARNING/ERROR]\n" << RESET;
		return (1);
	}
	Harl h;
	h.complain(av[1]);
}
