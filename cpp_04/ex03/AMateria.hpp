/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:58:20 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 16:32:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		virtual ~AMateria(void);

		std::string const 	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
