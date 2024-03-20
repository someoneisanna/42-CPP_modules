/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:33:14 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:51:44 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon(void);

		std::string const &getType(void);
		void setType(std::string type);
};

#endif
