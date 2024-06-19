/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:25:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/19 13:47:59 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

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

// obs.: When using polymorphism, it is recommended to make the destructor virtual
// so that the destructor of the derived class is called when deleting a base class pointer.

#endif
