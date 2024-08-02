/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:08:17 by ataboada          #+#    #+#             */
/*   Updated: 2024/08/02 10:05:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	system("clear");

	// Subject's Test ----------------------------------------------------------

	std::cout << "------------- SUBJECT'S MAIN -------------" << "\n\n";
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printStorage();
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}

	// Test 1 - Copies ---------------------------------------------------------

	std::cout << "\n------------- TEST 1 - COPIES -------------" << "\n\n";
	{
		Span sp1(3);
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);
		std::cout << "SP1(3)    - ";
		sp1.printStorage();

		Span sp2(sp1);
		std::cout << "SP2(SP1)  - ";
		sp2.printStorage();

		Span sp3 = sp1;
		std::cout << "SP3 = SP1 - ";
		sp3.printStorage();
	}

	// Test 2 - Add Numbers ---------------------------------------------------

	std::cout << "\n---------- TEST 2 - ADD NUMBERS -----------" << "\n\n";
	{
		Span sp(5);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.printStorage();

		std::vector<int> v;
		for (int i = 1; i < 50; i++)
			v.push_back(i);

		try 						{ sp.addNumber(v.begin(), v.end()); sp.printStorage(); }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }

		try 						{ sp.addNumber(4); }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }

		try 						{ sp.addNumber(v.begin(), v.end()); }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }
	}

	// Test 3 - Shortest Span -------------------------------------------------

	std::cout << "\n---------- TEST 3 - SHORTEST SPAN ---------" << "\n\n";
	{
		Span sp1(5);

		std::vector<int> v1;
		for (int i = 1; i < 5; i++)
			v1.push_back(i + 10);

		sp1.addNumber(v1.begin(), v1.end());
		sp1.printStorage();

		try 						{ std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }

		Span sp2(5);
		sp2.printStorage();

		try 						{ std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }

		sp2.addNumber(1);
		sp2.printStorage();

		try 						{ std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }
	}

	// Test 4 - Longest Span --------------------------------------------------
	{
		std::cout << "\n---------- TEST 4 - LONGEST SPAN ----------" << "\n\n";
		Span sp1(5);

		std::vector<int> v2;
		for (int i = 1; i < 5; i++)
			v2.push_back(i + 10);

		sp1.addNumber(v2.begin(), v2.end());
		sp1.printStorage();

		try 						{ std::cout << "Longest Span: " << sp1.longestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }

		Span sp2(5);
		sp2.printStorage();

		try 						{ std::cout << "Longest Span: " << sp2.longestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }

		sp2.addNumber(1);
		sp2.printStorage();

		try 						{ std::cout << "Longest Span: " << sp2.longestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }
	}

	// Test 5 - Bigger Arrays
	{
		std::cout << "\n---------- TEST 5 - BIGGER ARRAYS ---------" << "\n\n";
		Span sp1(20000);

		std::vector<int> v3;
		for (int i = 1; i < 20000; i++)
			v3.push_back(rand() % 100000);
		
		sp1.addNumber(v3.begin(), v3.end());

		try							{ std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }
		
		try							{ std::cout << "Longest Span : " << sp1.longestSpan() << std::endl; }
		catch (std::exception &e)	{ std::cout << e.what() << std::endl; }
	}
	std::cout << std::endl;
}
