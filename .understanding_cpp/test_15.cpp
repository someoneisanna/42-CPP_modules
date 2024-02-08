/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_15.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:58:02 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 19:00:36 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Using 'this' pointer in C++

class Calc
{
	private:
		int m_value;
	public:
		Calc(int value): m_value{value} {}
		int getValue() const { return m_value; }

		Calc& add(int value) { m_value += value; return *this; }
		Calc& sub(int value) { m_value -= value; return *this; }
		Calc& mul(int value) { m_value *= value; return *this; }
};

int main()
{
	Calc c {10};
	c.add(10).sub(5).mul(2);
	std::cout << "Value: " << c.getValue() << std::endl;
	return 0;
}
