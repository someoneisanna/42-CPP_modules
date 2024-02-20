/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:00:45 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/20 11:36:30 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		ICharacter() {};
		virtual ~ICharacter() {};

		virtual std::string const &getName() const = 0;

		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
