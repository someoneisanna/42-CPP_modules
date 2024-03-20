/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:29:37 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:14:41 by ataboada         ###   ########.fr       */
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
		Phonebook();
		~Phonebook();

		void	add_contact();
		void	search_contact();
};

int			check_index(int index);
std::string	word_cutter(std::string word);

#endif
