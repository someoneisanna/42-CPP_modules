/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:04:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 20:21:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual 			~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
