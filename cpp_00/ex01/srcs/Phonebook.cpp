/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:02:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/11 13:18:18 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// Constructor and Destructor --------------------------------------------------

Phonebook::Phonebook() : _index(0) {}
Phonebook::~Phonebook() {}

// Member Functions ------------------------------------------------------------

void Phonebook::add_contact()
{
	std::string fname, lname, nname, phone, secret;

	if (check_index(_index) == 1)
		return;
	std::cout << PURPLE << "************** ADDING CONTACT ***************" << RESET << std::endl;
	std::cout << "Enter first name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);
	if (fname.empty() || lname.empty() || nname.empty() || phone.empty() || secret.empty())
	{
		std::cout << RED << "Error: All fields are required." << RESET << std::endl;
		return;
	}
	_contacts[_index % 8].setContact(fname, lname, nname, phone, secret);
	_index++;
	std::cout << GREEN << "*************** CONTACT SAVED ***************" << RESET << std::endl;
}

void Phonebook::search_contact()
{
	std::string	index;

	if (_index == 0)
	{
		std::cout << RED << "No contacts to display." << RESET << std::endl;
		return;
	}
	std::cout << PURPLE << "************ DISPLAYING CONTACTS ************" << RESET << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _index && i < 8; i++)
	{
		std::cout
		<< "|         " << i << "|"
		<< std::setw(10) << word_cutter(_contacts[i].getFirstName()) << "|"
		<< std::setw(10) << word_cutter(_contacts[i].getLastName()) << "|"
		<< std::setw(10) << word_cutter(_contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << BOLD << "Enter the index of the contact you want to see: " << RESET;
	std::cin >> index;
	while (index.length() > 1 || index[0] < '0' || index[0] > (_index - 1 + '0'))
	{
		std::cout << RED << "Invalid index. Please enter a valid index: " << RESET;
		std::cin >> index;
	}
	_contacts[index[0] - '0'].displayContact();
	std::cin.ignore();
	std::cout << GREEN << "************* CONTACT DISPLAYED *************" << RESET << std::endl;
}

// Helper Functions ------------------------------------------------------------

int	check_index(int index)
{
	std::string cmd;

	if (index >= 8)
	{
		std::cout << RED << "Phonebook is full. If you add a contact, it" << std::endl;
		std::cout << "will replace the oldest contact you added." <<  RESET << std::endl;
		std::cout << BOLD << "Do you want to continue? (Y/N): " << RESET;
		std::getline(std::cin, cmd);
		if (cmd == "Y")
			return (0);
		else if (cmd == "N")
			return (1);
		else
		{
			std::cout << RED << "Invalid command. Returning to menu." << RESET << std::endl;
			return (1);
		}
	}
	return (0);
}

std::string word_cutter(std::string word)
{
	if (word.length() > 10)
		return (word.substr(0, 9) + ".");
	return (word);
}
