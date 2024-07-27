/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:26:44 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/27 18:03:09 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors, Destructor, and Assignment Overload --------------------------------

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **av) : _l(), _d()
{
	_fillContainers(av);
	_sortContainers();
}

PmergeMe::PmergeMe(PmergeMe const &src) : _l(src._l), _d(src._d) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		_l = src._l;
		_d = src._d;
	}
	return (*this);
}

// Member Functions ----------------------------------------------------------------

void PmergeMe::_fillContainers(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
			{
				std::cerr << "Error: Invalid input." << std::endl;
				exit(1);
			}
		}
		_l.push_back(atoi(av[i]));
		_d.push_back(atoi(av[i]));
	}
}

void PmergeMe::_sortContainers()
{
	std::cout << PURPLE << "Before: " << RESET;
	printList(_l);
	printDeque(_d);

	clock_t l_time = _sortList(_l);
	clock_t d_time = _sortDeque(_d);

	std::cout << PURPLE << "After : " << RESET;
	printList(_l);
	printDeque(_d);

	std::cout << "Time to process a range of " << _l.size() << " elements with std::list <int>: " << l_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << _d.size() << " elements with std::deque<int>: " << d_time << " ms" << std::endl;
}

void binaryInsertion(std::list<int> &l, int n)
{
	std::list<int>::iterator it = std::lower_bound(l.begin(), l.end(), n);
	l.insert(it, n);
}

clock_t PmergeMe::_sortList(std::list<int> &l)
{
	if (l.size() < 1)
		return (0);
		
	// Start timer
	clock_t start = clock();

	std::list<int>				a, b;
	std::list<int>::iterator	it, it_a, it_b;

	// 1st step: Pairwise comparison - sort each pair (a[i] > b[i])
	for (it = l.begin(); it != l.end();)
	{
		int first = *it++;
		if (it == l.end())
		{
			b.push_back(first);
			break;
		}
		int second = *it++;
		if (first < second)
		{
			a.push_back(second);
			b.push_back(first);
		}
		else
		{
			a.push_back(first);
			b.push_back(second);
		}
	}

	// 2nd step: Recursion - a is sorted recursively (a[i] < a[i+1] and a[i] > b[i])
	//recursiveListSort(a, b, 0);
	recursiveListSort(a, b, 0);
	
	// 3rd step: Insertion - 'b' is inserted into 'a' using Binary Insertion
	for (it_b = b.begin(); it_b != b.end(); it_b++)
		binaryInsertion(a, *it_b);
	
	// Copy sorted list back to original list
	l = a;
	return (clock() - start);
}

/*clock_t PmergeMe::_sortList(std::list<int> &l)
{
	clock_t start = clock();
	
	if (l.size() > 1)
	{
		std::list<int>				a, b;
		std::list<int>::iterator	it, it_a, it_b;

		// Create pairs of elements
		for (it = l.begin(); it != l.end();)
		{
			a.push_back(*it);
			it++;
			if (it != l.end())
			{
				b.push_back(*it);
				it++;
			}
			if (it == l.end() && a.size() > b.size())
			{
				b.push_back(a.back());
				a.pop_back();
			}
		}

		// 1st step: Pairwise comparison - sort each pair (a[i] > b[i])
		for (it_a = a.begin(), it_b = b.begin(); it_a != a.end(); it_a++, it_b++)
		{
			if (*it_a < *it_b)
				std::swap(*it_a, *it_b);
		}

		// 2nd step: Recursion - a is sorted recursively (a[i] < a[i+1] and a[i] > b[i])
		recursiveListSort(a, b, 0);

		// 3rd step: Insertion - 'b' is inserted into 'a' using Binary Insertion
		for (it_b = b.begin(); it_b != b.end(); it_b++)
		{
			it = std::lower_bound(a.begin(), a.end(), *it_b);
			a.insert(it, *it_b);
		}

		// Copy sorted list back to original list
		l = a;

	}
	return (clock() - start);
}*/

clock_t PmergeMe::_sortDeque(std::deque<int> &d)
{
	clock_t start = clock();
	if (d.size() > 1)
	{
		std::deque<int>				a, b;
		std::deque<int>::iterator	it, it_a, it_b;

		// Create pairs of elements
		for (it = d.begin(); it != d.end();)
		{
			a.push_back(*it);
			it++;
			if (it != d.end())
			{
				b.push_back(*it);
				it++;
			}
			if (it == d.end() && a.size() > b.size())
			{
				b.push_back(a.back());
				a.pop_back();
			}
		}

		// 1st step: Pairwise comparison - sort each pair (a[i] > b[i])
		for (it_a = a.begin(), it_b = b.begin(); it_a != a.end(); it_a++, it_b++)
		{
			if (*it_a < *it_b)
				std::swap(*it_a, *it_b);
		}

		// 2nd step: Recursion - a is sorted recursively (a[i] < a[i+1] and a[i] > b[i])
		recursiveDequeSort(a, b, 0);

		// 3rd step: Insertion - 'b' is inserted into 'a' using Binary Insertion
		for (it_b = b.begin(); it_b != b.end(); it_b++)
		{
			it = std::lower_bound(a.begin(), a.end(), *it_b);
			a.insert(it, *it_b);
		}

		// Copy sorted deque back to original deque
		d = a;
	}
	return (clock() - start);
}

// Helper Functions ----------------------------------------------------------------

void printList(std::list<int> l)
{
	std::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		std::cout << *it;
		it++;
		if (it != l.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void printDeque(std::deque<int> d)
{
	std::deque<int>::iterator it = d.begin();
	while (it != d.end())
	{
		std::cout << *it;
		it++;
		if (it != d.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void recursiveListSort(std::list<int> &a, std::list<int> &b, unsigned int i)
{
	a.sort();

	std::list<int>::iterator it_a = a.begin();
	std::list<int>::iterator it_b = b.begin();
	std::advance(it_a, i);
	std::advance(it_b, i);

	if (*it_a < *it_b)
		std::swap(*it_a, *it_b);

	if (i < a.size() - 1)
		recursiveListSort(a, b, i + 1);
}

void recursiveDequeSort(std::deque<int> &a, std::deque<int> &b, unsigned int i)
{
	std::sort(a.begin(), a.end());

	std::deque<int>::iterator it_a = a.begin();
	std::deque<int>::iterator it_b = b.begin();
	std::advance(it_a, i);
	std::advance(it_b, i);

	if (*it_a < *it_b)
		std::swap(*it_a, *it_b);

	if (i < a.size() - 1)
		recursiveDequeSort(a, b, i + 1);
}
