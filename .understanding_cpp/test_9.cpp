/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_9.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:16:38 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 16:21:33 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Classes: Get and Set functions.

class Date
{
	private:
		int m_day {07};
		int m_month {02};
		int m_year {2024};
	public:
		void print_date()
		{
			std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
		}
		int getDay() const { return m_day; }
		int getMonth() const { return m_month; }
		int getYear() const { return m_year; }
		void setDay(int day) { m_day = day; }
		void setMonth(int month) { m_month = month; }
		void setYear(int year) { m_year = year; }
};

int main()
{
	Date d;
	d.setYear(4200);
	std::cout << "Year: " << d.getYear() << std::endl;
	d.setMonth(42);
	std::cout << "Month: " << d.getMonth() << std::endl;
	d.setDay(42);
	std::cout << "Day: " << d.getDay() << std::endl;
	d.print_date();
	return 0;
}
