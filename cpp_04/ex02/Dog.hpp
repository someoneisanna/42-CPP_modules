/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:30:08 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/19 14:26:48 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog &operator=(Dog const &src);

		Brain *getBrain(void) const;

		void makeSound(void) const;
};

#endif
