/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:30:08 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/19 14:23:57 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);	// Virtual destructor is a good practice when dealing with polymorphism

		Dog &operator=(Dog const &src);

		Brain *getBrain(void) const;

		void makeSound(void) const;
};

#endif
