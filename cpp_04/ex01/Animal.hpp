/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:25:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:00:59 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

// INCLUDES --------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <string>

// COLORS ----------------------------------------------------------------------

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define BOLD		"\033[1m"

// CLASS -----------------------------------------------------------------------

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);
		virtual ~Animal(void);

		Animal &operator=(Animal const &animal);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
