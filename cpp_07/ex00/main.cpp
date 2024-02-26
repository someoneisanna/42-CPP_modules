/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:11:49 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/26 17:02:21 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	// INT TESTS -------------------------------------------------------------
	int a = 2;
	int b = 3;

	std::cout << "Original Values: ";
	std::cout << "a: " << a << " b: " << b << std::endl;

	::swap(a, b);
	std::cout << "Swapped Values:  ";
	std::cout << "a: " << a << " b: " << b << std::endl;

	std::cout << "Min Value: " << ::min(a, b) << std::endl;
	std::cout << "Max Value: " << ::max(a, b) << std::endl;

	// FLOAT TESTS ------------------------------------------------------------
	float c = 2.5f;
	float d = 3.5f;

	std::cout << "\nOriginal Values: ";
	std::cout << "c: " << c << " d: " << d << std::endl;

	::swap(c, d);
	std::cout << "Swapped Values:  ";
	std::cout << "c: " << c << " d: " << d << std::endl;

	std::cout << "Min Value: " << ::min(c, d) << std::endl;
	std::cout << "Max Value: " << ::max(c, d) << std::endl;

	// DOUBLE TESTS -----------------------------------------------------------
	double e = 2.5;
	double f = 3.5;

	std::cout << "\nOriginal Values: ";
	std::cout << "e: " << e << " f: " << f << std::endl;
	::swap(e, f);
	std::cout << "Swapped Values:  ";
	std::cout << "e: " << e << " f: " << f << std::endl;
	std::cout << "Min Value: " << ::min(e, f) << std::endl;
	std::cout << "Max Value: " << ::max(e, f) << std::endl;

	// CHAR TESTS -------------------------------------------------------------
	char g = 'a';
	char h = 'b';

	std::cout << "\nOriginal Values: ";
	std::cout << "g: " << g << " h: " << h << std::endl;
	::swap(g, h);
	std::cout << "Swapped Values:  ";
	std::cout << "g: " << g << " h: " << h << std::endl;
	std::cout << "Min Value: " << ::min(g, h) << std::endl;
	std::cout << "Max Value: " << ::max(g, h) << std::endl;

	// STRING TESTS ------------------------------------------------------------
	std::string i = "hello";
	std::string j = "bye";

	std::cout << "\nOriginal Values: ";
	std::cout << "i: " << i << " j: " << j << std::endl;
	::swap(i, j);
	std::cout << "Swapped Values:  ";
	std::cout << "i: " << i << " j: " << j << std::endl;
	std::cout << "Min Value: " << ::min(i, j) << std::endl;
	std::cout << "Max Value: " << ::max(i, j) << std::endl;

	// SUBJECTS TESTS ----------------------------------------------------------
	std::cout << "\nSUBJECTS TESTS" << std::endl;
	int k = 2;
	int l = 3;

	::swap( k, l );
	std::cout << "k = " << k << ", l = " << l << std::endl;
	std::cout << "min( k, l ) = " << ::min( k, l ) << std::endl;
	std::cout << "max( k, l ) = " << ::max( k, l ) << std::endl;

	std::string m = "chaine1";
	std::string n = "chaine2";

	::swap(m, n);
	std::cout << "m = " << m << ", n = " << n << std::endl;
	std::cout << "min( m, n ) = " << ::min( m, n ) << std::endl;
	std::cout << "max( m, n ) = " << ::max( m, n ) << std::endl;
}
