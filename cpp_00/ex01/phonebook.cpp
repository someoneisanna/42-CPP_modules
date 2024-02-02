/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:02:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/02 19:31:17 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void		add_contact(PhoneBook &phonebook);
void		search_contact(PhoneBook &phonebook);
std::string	word_cutter(std::string word);

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	phonebook.n_contacts = 0;
	while (1)
	{
		std::cout << "Enter a command (ADD | SEARCH | EXIT): ";
		std::cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			add_contact(phonebook);
		else if (command == "SEARCH")
			search_contact(phonebook);
	}
}

void	add_contact(PhoneBook &phonebook)
{
	Contact	new_contact;
	std::string	confirmation;

	if (phonebook.n_contacts == 8)
	{
		std::cout << RED << "Phonebook is full. If you add a new contact,\n";
		std::cout << "the oldest one will be deleted. Do you want\n";
		std::cout << "to continue? (Y/N): " << RESET;
		std::cin >> confirmation;
		if (confirmation == "N")
			return;
		else if (confirmation == "Y")
			phonebook.n_contacts--;
		else
			return;
	}
	std::cout << PURPLE << "************** ADDING NEW CONTACT *************" << RESET << std::endl;
	std::cin.ignore();
	std::cout << "Enter first name: ";
	std::getline(std::cin, new_contact.first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, new_contact.last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, new_contact.nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, new_contact.phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, new_contact.darkest_secret);
	if (new_contact.first_name.length() == 0
		|| new_contact.last_name.length() == 0
		|| new_contact.nickname.length() == 0
		|| new_contact.phone_number.length() == 0
		|| new_contact.darkest_secret.length() == 0)
	{
		std::cout << RED << "Invalid input. Please enter all the fields." << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "*************** CONTACT ADDED ***************" << RESET << std::endl;
	phonebook.contacts[phonebook.n_contacts] = new_contact;
	phonebook.n_contacts++;
}

void	search_contact(PhoneBook &phonebook)
{
	int	index = -42;

	if (phonebook.n_contacts == 0)
	{
		std::cout << RED << "No contacts to display." << RESET << std::endl;
		return;
	}
	std::cout << PURPLE << "************ DISPLAYING CONTACTS ************" << RESET << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < phonebook.n_contacts; i++)
	{
		std::cout << "|         " << i + 1 << "|"
		<< word_cutter(phonebook.contacts[i].first_name)
		<< word_cutter(phonebook.contacts[i].last_name)
		<< word_cutter(phonebook.contacts[i].nickname) << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Enter the index of the contact you want to see: ";
	std::cin >> index;
	while (index < 1 || index > phonebook.n_contacts)
	{
		std::cout << RED << "Invalid index. Please enter a valid index: " << RESET;
		std::cin >> index;
	}
	if (index > 0 && index <= phonebook.n_contacts)
	{
		std::cout << GREEN << "************** CONTACT DETAILS **************" << RESET << std::endl;
		std::cout << "First Name: " << phonebook.contacts[index - 1].first_name << std::endl;
		std::cout << "Last Name: " << phonebook.contacts[index - 1].last_name << std::endl;
		std::cout << "Nickname: " << phonebook.contacts[index - 1].nickname << std::endl;
		std::cout << "Phone Number: " << phonebook.contacts[index - 1].phone_number << std::endl;
		std::cout << "Darkest Secret: " << phonebook.contacts[index - 1].darkest_secret << std::endl;
		std::cout << GREEN << "*********************************************" << RESET << std::endl;
	}
}

std::string	word_cutter(std::string word)
{
	std::string	cut_word;

	if (word.length() > 10)
	{
		cut_word = word.substr(0, 9);
		cut_word += ".";
	}
	else
	{
		for (int i = 10 - word.length(); i > 0; i--)
			cut_word += " ";
		cut_word += word;
	}
	cut_word += "|";
	return (cut_word);
}

