/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:15:36 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 17:12:25 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &e))
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void print(T &e)
{
	std::cout << e << std::endl;
}


#endif
