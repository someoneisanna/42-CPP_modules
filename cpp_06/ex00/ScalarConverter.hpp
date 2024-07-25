/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:24:07 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/18 15:45:38 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

# define RESET	"\033[0m"
# define BOLD	"\033[1m"
# define RED	"\033[0;31m"
# define PURPLE	"\033[0;35m"

# define CHAR	1
# define INT	2
# define FLOAT	3
# define DOUBLE	4
# define PSEUDO	5

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &src);

	public:
		static void convert(std::string input);
};

#endif
