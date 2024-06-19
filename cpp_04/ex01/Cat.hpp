/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:30:18 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/19 14:24:04 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);	// Virtual destructor is a good practice when dealing with polymorphism

		Cat &operator=(Cat const &src);

		Brain *getBrain(void) const;

		void makeSound(void) const;
};

#endif
