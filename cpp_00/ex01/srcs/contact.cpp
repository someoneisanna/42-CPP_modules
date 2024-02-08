/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:19:33 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/08 18:11:59 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

std::string const Contact::getFirstName() { return _first_name; }
std::string const Contact::getLastName() { return _last_name; }
std::string const Contact::getNickname() { return _nickname; }
std::string const Contact::getPhoneNumber() { return _phone_number; }
std::string const Contact::getDarkestSecret() { return _darkest_secret; }

void Contact::setContact(std::string &first_name,
						std::string &last_name,
						std::string &nickname,
						std::string &phone_number,
						std::string &darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}

void Contact::displayContact()
{
	std::cout << "First Name: " << _first_name << std::endl;
	std::cout << "Last Name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phone_number << std::endl;
	std::cout << "Darkest Secret: " << _darkest_secret << std::endl;
}
