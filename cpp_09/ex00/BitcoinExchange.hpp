/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:23:22 by ataboada          #+#    #+#             */
/*   Updated: 2024/08/02 10:13:11 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::string						_filename;
		std::map<std::string, float>	_database;

		void	_readDatabase();
		void	_convertValue();
		float	_searchDatabase(std::string date);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &src);
};

bool	isValidDate(std::string date);
bool	isValidValue(std::string s, float f);

#endif
