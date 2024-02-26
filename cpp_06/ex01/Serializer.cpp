/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:54:25 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 08:15:45 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructor, Destructor, Assignment Operator --------------------------------

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &src) { *this = src; }
Serializer::~Serializer() {}
Serializer &Serializer::operator=(Serializer const &src)
{
	(void)src;
	return (*this);
}

// Member Functions ------------------------------------------------------------

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}


