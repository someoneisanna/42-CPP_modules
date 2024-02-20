/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/20 15:44:21 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria			*_inventory[4];
		AMateria			*_adresses[4];
		int					_inventoryCount;
		std::string			_name;
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character(void);

		Character &operator=(Character const &src);

		std::string const &getName(void) const;

		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
