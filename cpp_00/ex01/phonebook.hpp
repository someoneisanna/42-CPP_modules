/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:29:37 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/02 19:49:00 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

#define RED		"\033[0;91m"
#define GREEN	"\033[0;92m"
#define PURPLE	"\033[0;95m"
#define RESET	"\033[0m"

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	public:
		Contact	contacts[8];
		int		n_contacts;
};

#endif
