/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:14:01 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 19:40:24 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);

		Cure &operator=(Cure const &src);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
