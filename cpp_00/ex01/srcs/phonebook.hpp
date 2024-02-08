/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:29:37 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/08 14:18:46 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../header.hpp"

class Phonebook
{
	private:
		Contact	_contacts[8];
		int		_index;
	public:
		Phonebook() { _index = 0; };
		~Phonebook() {};
		void	add_contact();
		void	search_contact();
};

#endif
