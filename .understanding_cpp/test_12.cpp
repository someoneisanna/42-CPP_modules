/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_12.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:19:23 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 17:29:49 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Here we understand how to use constructors in C++.
// Constructors are special member functions that are called when an object of a class is created.
// We should not use it like an assignment operator. This would be WRONG:
// Date(int day, int month, int year)
// {
//		m_day = day;
//		m_month = month;
//		m_year = year;
// }

class Date
{
	private:
		int m_day;
		int m_month;
		int m_year;
	public:
		Date(int day, int month, int year): m_day{day}, m_month{month}, m_year{year} {} // constructor
		void print_date()
		{
			std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
		}
};

int main()
{
	Date d {07, 02, 2024};
	d.print_date();
	return 0;
}

