/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:24:06 by ataboada          #+#    #+#             */
/*   Updated: 2024/08/02 10:40:43 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors, Destructor & Assignment Overloads -----------------------------

BitcoinExchange::BitcoinExchange() : _filename("") {}

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename)
{
	_readDatabase();
	_convertValue();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		_filename = src._filename;
		_database = src._database;
	}
	return (*this);
}

// Member Functions ------------------------------------------------------------

void BitcoinExchange::_readDatabase()
{
	std::ifstream	file("data.csv");
	std::string		line, key, value;

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open 'data.csv' file" << std::endl;
		exit(1);
	}
	std::getline(file, key);
	while (file.good())
	{
		std::getline(file, key, ',');
		std::getline(file, value);
		if (!key.empty() && !value.empty())
			_database[key] = std::atof(value.c_str());
	}
}

void BitcoinExchange::_convertValue()
{
	std::ifstream	file(this->_filename.c_str());
	std::string		header, line, date, svalue;
	float			fvalue, result;

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open '" << _filename << "' file" << std::endl;
		exit(1);
	}
	std::getline(file, header);
	if (!header.empty() && header != "date | value")
		std::cerr << "Warning: This will be ignored as it should be the header" << std::endl;
	while (std::getline(file, line))
	{
		if (line.find('|') == std::string::npos)
			std::cerr << "Error: Bad Input" << std::endl;
		else
		{
			date = line.substr(0, line.find('|'));
			svalue = line.substr(line.find('|') + 2);
			fvalue = std::atof(svalue.c_str());
			if (!isValidDate(date))
				std::cerr << "Error: Invalid date format" << std::endl;
			else if (!isValidValue(svalue, fvalue))
				std::cerr << "Error: Invalid value format" << std::endl;
			else
			{
				result = fvalue * _searchDatabase(date);
				std::cout << date << " => " << svalue << " = " << result << std::endl;
			}
		}
	}
}

float BitcoinExchange::_searchDatabase(std::string date)
{
	if (_database.find(date) != _database.end())
		return (_database[date]);
	else
	{
		std::map<std::string, float>::const_iterator it;
		it = this->_database.lower_bound(date);
		if (it != this->_database.begin())
			it--;
		return (it->second);
	}
}

// Helper Functions ------------------------------------------------------------

bool isValidDate(std::string date)
{
	if (date.length() != 11)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (date[5] > '1' || (date[5] == '1' && date[6] > '2'))
			return (false);
		if (date[8] > '3' || (date[8] == '3' && date[9] > '1'))
			return (false);
		if ((date[5] == '0' && date[6] == '0') || (date[8] == '0' && date[9] == '0'))
			return (false);
		if ((date[i] < '0' || date[i] > '9') && (i != 4 && i != 7))
			return (false);
	}
	return (true);
}

bool isValidValue(std::string s, float f)
{
	int dot_found = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			dot_found++;
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
			return (false);
	}
	if (dot_found > 1 || f < 0 || f > 1000)
		return (false);
	return (true);
}
