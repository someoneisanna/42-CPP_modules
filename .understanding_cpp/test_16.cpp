/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_16.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:08:37 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 19:11:20 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Destructors in C++

class Example
{
	private:
		int m_id;
	public:
		Example(int id): m_id {id} { std::cout << "Constructor: " << m_id << "\n"; }
		~Example() { std::cout << "Destructor: " << m_id << "\n"; }
		int getId() const { return m_id; }
};

int main()
{
	Example e1 {1};
	Example e2 {2};
	return 0;
}
