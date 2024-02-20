/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:30:08 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:53 by ataboada         ###   ########.fr       */
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
		~Dog(void);

		Dog &operator=(Dog const &src);

		virtual void makeSound(void) const;
};

#endif
