/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_10.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:29:07 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 16:40:12 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Classes: Get and Set functions, but more efficient.
// obs.: we could also use 'auto' instead of 'const std::string &'. that way, the program
// would automatically detect the type of the variable, as it should always be the same type
// as the return type of the function (member of the class).

class Employee
{
	private:
		std::string m_name;
	public:
		const std::string &getName() const { return m_name; } // tip: always use 'const' when returning a reference
		void setName(std::string name) { m_name = name; }
};

int main()
{
	Employee e;
	e.setName("John");
	std::cout << e.getName() << std::endl;
	return 0;
}
