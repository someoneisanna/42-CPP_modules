/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:30:18 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:51 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat &operator=(Cat const &src);

		virtual void makeSound(void) const;
};

#endif
