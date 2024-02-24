/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:40:50 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 16:44:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

// ------------- COLORS -------------

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define RED			"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define CYAN		"\033[36m"

// ----------------------------------

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		void complain(std::string level);
};

#endif
