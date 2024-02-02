/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:24:33 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/01 20:34:43 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
	else
	{
		int i = 0;
		while (av[++i])
		{
			int j = -1;
			while (av[i][++j])
				std :: cout << (char)toupper(av[i][j]);
		}
		std :: cout << std :: endl;
	}
}
