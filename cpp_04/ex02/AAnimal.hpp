/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:25:47 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 16:36:23 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

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

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);

		AAnimal &operator=(AAnimal const &src);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
