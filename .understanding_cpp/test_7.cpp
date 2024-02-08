/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_7.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:44:48 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 15:55:01 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Here we learn how to use classes in C++ with private members.

class Date
{
	private: // this is not necessary, as it is private by default
		int m_day {07};
		int m_month {02};
		int m_year {2024};
	public:
		void print_date()
		{
			std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
		}
};

int main()
{
	Date d;
	d.print_date();
	return 0;
}
