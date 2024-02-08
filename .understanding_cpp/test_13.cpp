/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_13.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:40:38 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 17:46:56 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Constructors in C++: default arguments
// They are used to initialize the object with default values (if no arguments are provided).
// If you don't provide a constructor, the compiler will provide a default constructor for you:
// Date() {}

class Date
{
	private:
		int m_day;
		int m_month;
		int m_year;
	public:
		Date(int day=01, int month=01, int year=2001): m_day{day}, m_month{month}, m_year{year}
		{
			std::cout << "Date constructed: " << m_day << "/" << m_month << "/" << m_year << std::endl;
		}
};

int main()
{
	Date d1;
	Date d2 {07, 02, 2024};
	return 0;
}
