/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_8.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:00:21 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 16:31:35 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Continuation of classes in C++ with private members.

class Person
{
	private:
		std::string m_name;
	public:
		void kills(const Person &p) const
		{
			std::cout << m_name << " kills " << p.m_name << std::endl;
		}
		void setName(const std::string &name)
		{
			m_name = name;
		}
};

int main()
{
	Person p1;
	p1.setName("David");

	Person p2;
	p2.setName("Goliath");

	p1.kills(p2);
	return 0;
}
