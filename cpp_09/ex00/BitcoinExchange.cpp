/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:24:06 by ataboada          #+#    #+#             */
/*   Updated: 2024/08/07 15:42:29 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors, Destructor & Assignment Overloads -----------------------------

BitcoinExchange::BitcoinExchange() : _filename("") {}

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename)
{
	if (_readDatabase() == 1)
		return;
	if (_convertValue() == 1)
		return;
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

int BitcoinExchange::_readDatabase()
{
	std::ifstream	file("data.csv");
	std::string		line, key, value;

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open 'data.csv' file" << std::endl;
		return (1);
	}
	std::getline(file, key);
	while (file.good())
	{
		std::getline(file, key, ',');
		std::getline(file, value);
		if (!key.empty() && !value.empty())
			_database[key] = std::atof(value.c_str());
	}
	return (0);
}

int BitcoinExchange::_convertValue()
{
	std::ifstream	file(this->_filename.c_str());
	std::string		header, line, date, svalue;
	float			fvalue, result;
	size_t			pipe_index, i;

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open '" << _filename << "' file" << std::endl;
		_database.clear();
		return (1);
	}
	std::getline(file, header);
	if (!header.empty() && !std::isalpha(header[0]))
		std::cerr << "Warning: This will be ignored as it should be the header" << std::endl;
	while (std::getline(file, line))
	{
		pipe_index = line.find('|');
		if (pipe_index == std::string::npos || !line[pipe_index + 1])
			std::cerr << "Error: Bad Input" << std::endl;
		else
		{
			for (i = 0; i < line.length() && line[i] == ' '; i++)
				;
			date = line.substr(i, pipe_index - i);
			svalue = line.substr(pipe_index + 1);
			fvalue = std::atof(svalue.c_str());
			if (!isValidDate(date))
				std::cerr << "Error: Invalid date format" << std::endl;
			else if (!isValidValue(svalue, fvalue))
				std::cerr << "Error: Invalid value format" << std::endl;
			else
			{
				result = fvalue * _searchDatabase(_date);
				std::cerr << _date << " => " << fvalue << " = " << result << std::endl;
			}
		}
	}
	return (0);
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

bool BitcoinExchange::isValidDate(std::string date)
{
	int					year, month, day;
	char				d1, d2;
	std::istringstream	deconstructDate(date);
	std::ostringstream	reconstructDate;

	if (!(deconstructDate >> year >> d1 >> month >> d2 >> day))
		return (false);
	if (d1 != '-' || d2 != '-')
		return (false);
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (leapYear && day > 29)
			return (false);
		else if (!leapYear && day > 28)
			return (false);
	}
	
	reconstructDate << std::setw(4) << std::setfill('0') << year << '-'
					<< std::setw(2) << std::setfill('0') << month << '-' 
					<< std::setw(2) << std::setfill('0') << day;
	_date = reconstructDate.str();

	return (true);
}

bool BitcoinExchange::isValidValue(std::string s, float f)
{
	int dot_found = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			dot_found++;
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.' && s[i] != ' ')
			return (false);
	}
	if (dot_found > 1 || f < 0 || f > 1000)
		return (false);
	return (true);
}
