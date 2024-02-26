/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 17:16:15 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	// STRING ARRAY TEST -------------------------------------------------------

	std::cout << "---- STRING ARRAY TEST ----" << std::endl;

	std::string	array_str[] = {"London", "Paris", "Rio de Janeiro", "Madrid", "Tokyo"};
	size_t		array_len = sizeof(array_str) / sizeof(array_str[0]);

	::iter(array_str, array_len, ::print);

	// INT ARRAY TEST ----------------------------------------------------------

	std::cout << "------ INT ARRAY TEST -----" << std::endl;

	int	array_int[] = {1, 2, 3, 4, 5};
	array_len = sizeof(array_int) / sizeof(array_int[0]);

	::iter(array_int, array_len, ::print);

	// FLOAT ARRAY TEST --------------------------------------------------------

	std::cout << "---- FLOAT ARRAY TEST -----" << std::endl;

	float	array_float[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	array_len = sizeof(array_float) / sizeof(array_float[0]);

	::iter(array_float, array_len, ::print);
}
