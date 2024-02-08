/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_17.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:21:34 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 19:25:26 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Static member variables in C++

class Something
{
	private:
		static inline int s_idGenerator {1}; // inline keyword is used to define a static member variable in the class definition.
		int m_id;
	public:
		Something(): m_id {s_idGenerator++} {}
		int getId() const { return m_id; }
};

int main()
{
	Something s1{};
	Something s2{};
	Something s3{};

	std::cout << s1.getId() << std::endl;
	std::cout << s2.getId() << std::endl;
	std::cout << s3.getId() << std::endl;
	return 0;
}
