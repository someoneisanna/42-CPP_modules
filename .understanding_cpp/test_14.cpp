/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_14.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:57:43 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/07 18:01:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Constructors in C++: temporary class type objects

class Numbers
{
	private:
		int x;
		int y;
	public:
		Numbers(int x, int y): x{x}, y{y} { }
		int getX() const { return x; }
		int getY() const { return y; }
};

void	printNumbers(Numbers n)
{
	std::cout << "x: " << n.getX() << " y: " << n.getY() << std::endl;
}

int main()
{
	// case 1
	Numbers n {1, 2};
	printNumbers(n);

	// case 2
	printNumbers(Numbers {3, 4});

	// case 3
	printNumbers(Numbers {5, 6});
	return 0;
}
