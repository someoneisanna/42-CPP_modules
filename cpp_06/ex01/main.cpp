/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 08:32:38 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t raw;

	data.s = "Hello, World!";
	data.n = 42;

	std::cout << "Original Address (in hex): " << &data << std::endl;
	std::cout << "Original Address (in int): " << reinterpret_cast<uintptr_t>(&data) << std::endl;
	std::cout << "Original Data            : " << data.s << " " << data.n << std::endl << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << "Serialized Data          : " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data        : " << ptr->s << " " << ptr->n << std::endl;

	return 0;
}
