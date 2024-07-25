/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:58:35 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/25 16:04:18 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm> // std::find
#include <vector>    // std::vector
#include <list>      // std::list

template <typename T>
int easyfind(T &container, int value)
{
	typename T::iterator ptr = std::find(container.begin(), container.end(), value);
	if (ptr == container.end())
		throw std::exception();
	std::cout << "Value found" << std::endl;
	return (*ptr);
}

#endif
