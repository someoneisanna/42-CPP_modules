/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:12:28 by ataboada          #+#    #+#             */
/*   Updated: 2024/03/18 18:12:18 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.hpp"

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:
		std::string const getFirstName();
		std::string const getLastName();
		std::string const getNickname();
		std::string const getPhoneNumber();
		std::string const getDarkestSecret();

		void setContact(std::string &first_name,
						std::string &last_name,
						std::string &nickname,
						std::string &phone_number,
						std::string &darkest_secret);

		void displayContact();
};

#endif
