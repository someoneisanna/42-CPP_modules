/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:11:49 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/25 14:29:11 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	// INT TESTS -------------------------------------------------------------
	std::cout << "INT TESTS ***********************" << std::endl;
	int a = 2;
	int b = 3;

	std::cout << "\nOriginal Values: ";
	std::cout << "a: " << a << " | b: " << b << std::endl;

	::swap(a, b);
	std::cout << "Swapped Values:  ";
	std::cout << "a: " << a << " | b: " << b << std::endl;

	std::cout << "Min Value: " << ::min(a, b) << std::endl;
	std::cout << "Max Value: " << ::max(a, b) << std::endl;

	// FLOAT TESTS ------------------------------------------------------------
	std::cout << "\nFLOAT TESTS ********************" << std::endl;
	float c = 2.5f;
	float d = 3.5f;

	std::cout << "\nOriginal Values: ";
	std::cout << "c: " << c << " | d: " << d << std::endl;

	::swap(c, d);
	std::cout << "Swapped Values:  ";
	std::cout << "c: " << c << " | d: " << d << std::endl;

	std::cout << "Min Value: " << ::min(c, d) << std::endl;
	std::cout << "Max Value: " << ::max(c, d) << std::endl;

	// DOUBLE TESTS -----------------------------------------------------------
	std::cout << "\nDOUBLE TESTS *******************" << std::endl;
	double e = 2.5;
	double f = 3.5;

	std::cout << "\nOriginal Values: ";
	std::cout << "e: " << e << " | f: " << f << std::endl;
	::swap(e, f);
	std::cout << "Swapped Values:  ";
	std::cout << "e: " << e << " | f: " << f << std::endl;
	std::cout << "Min Value: " << ::min(e, f) << std::endl;
	std::cout << "Max Value: " << ::max(e, f) << std::endl;

	// CHAR TESTS -------------------------------------------------------------
	std::cout << "\nCHAR TESTS *********************" << std::endl;
	char g = 'a';
	char h = 'b';

	std::cout << "\nOriginal Values: ";
	std::cout << "g: " << g << " | h: " << h << std::endl;
	::swap(g, h);
	std::cout << "Swapped Values:  ";
	std::cout << "g: " << g << " | h: " << h << std::endl;
	std::cout << "Min Value: " << ::min(g, h) << std::endl;
	std::cout << "Max Value: " << ::max(g, h) << std::endl;

	// STRING TESTS ------------------------------------------------------------
	std::cout << "\nSTRING TESTS *******************" << std::endl;
	std::string i = "hello";
	std::string j = "bye";

	std::cout << "\nOriginal Values: ";
	std::cout << "i: " << i << " | j: " << j << std::endl;
	::swap(i, j);
	std::cout << "Swapped Values:  ";
	std::cout << "i: " << i << " | j: " << j << std::endl;
	std::cout << "Min Value: " << ::min(i, j) << std::endl;
	std::cout << "Max Value: " << ::max(i, j) << std::endl;

	// SUBJECTS TESTS ----------------------------------------------------------
	std::cout << "\nSUBJECTS TESTS *****************" << std::endl;
	int k = 2;
	int l = 3;

	::swap( k, l );
	std::cout << "\nk = " << k << ", l = " << l << std::endl;
	std::cout << "min( k, l ) = " << ::min( k, l ) << std::endl;
	std::cout << "max( k, l ) = " << ::max( k, l ) << std::endl;

	std::string m = "chaine1";
	std::string n = "chaine2";

	::swap(m, n);
	std::cout << "m = " << m << ", n = " << n << std::endl;
	std::cout << "min( m, n ) = " << ::min( m, n ) << std::endl;
	std::cout << "max( m, n ) = " << ::max( m, n ) << std::endl;

	// INCOMPATIBLE TYPES TESTS -----------------------------------------------
	std::cout << "\nINCOMPATIBLE TYPES TESTS *******" << std::endl;
	int o = 2;
	//float p = 3;
	int p = 3;

	std::cout << "\nBefore SWAP: o = " << o << ", p = " << p << std::endl;
	::swap(o, p);
	std::cout << "After SWAP:  o = " << o << ", p = " << p << std::endl;
	std::cout << "min(o, p) = " << ::min(o, p) << std::endl;
	std::cout << "max(o, p) = " << ::max(o, p) << std::endl;
}
