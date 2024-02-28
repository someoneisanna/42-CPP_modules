/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/28 13:12:21 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	system("clear");

	// Subject's Test ----------------------------------------------------------
	{
		std::cout << "------------------ Subject's Test ------------------" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Last int: " << mstack.top() << std::endl;
		mstack.pop();

		std::cout << "Size after deleting the last int: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Iterating through the stack         : ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::stack<int> s(mstack);
		std::cout << "Iterating through the copied stack: : ";
		for (int i = 0; i < 5; i++)
		{
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << "\n\n";
	}

	// My Test ----------------------------------------------------------------
	{
		std::cout << "---------------------- My Test ----------------------" << std::endl;

		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << "Last int: " << lst.back() << std::endl;
		lst.pop_back();

		std::cout << "Size after deleting the last int: " << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;

		std::cout << "Iterating through the stack         : ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::list<int> s(lst);
		std::cout << "Iterating through the copied stack: : ";
		for (int i = 0; i < 5; i++)
		{
			std::cout << s.back() << " ";
			s.pop_back();
		}
		std::cout << "\n\n";
	}
}
