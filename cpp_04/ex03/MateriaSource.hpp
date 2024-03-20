/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:22:11 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/20 16:35:36 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[4];
		int			_inventoryCount;

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);

		MateriaSource &operator=(MateriaSource const &src);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif
