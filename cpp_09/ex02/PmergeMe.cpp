/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:26:44 by ataboada          #+#    #+#             */
/*   Updated: 2024/07/28 14:54:51 by ataboada         ###   ########.fr       */
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
	printContainer(_l);
	std::cout << "        ";
	printContainer(_d);

	clock_t l_time = _sortList(_l);
	clock_t d_time = _sortDeque(_d);

	std::cout << PURPLE << "After : " << RESET;
	printContainer(_l);
	std::cout << "        ";
	printContainer(_d);

	std::cout << "Time to process a range of " << _l.size() << " elements with std::list <int>: " << l_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << _d.size() << " elements with std::deque<int>: " << d_time << " ms" << std::endl;
}

clock_t PmergeMe::_sortList(std::list<int> &l)
{
	if (l.size() < 1)
		return (0);
		
	// Start timer
	clock_t start = clock();

	int							n_erased, b_size;
	std::list<int>				a, b, jacobsthal;
	std::list<int>::iterator	it, it_b, it_j;

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
	recursiveListSort(a, b, 0);

	// 3rd step: Insertion - 'b' is inserted into 'a' using Binary Insertion

	// Here, we work in batches of elements
	// The Jacobsthal sequence is used to determine the position of the element that will be inserted
	// For example:
	// First Batch  | k = 1 | t_k = 1  | to be inserted in A: b1
	// Second Batch | k = 2 | t_k = 3  | to be inserted in A: b3, b2
	// Third Batch  | k = 3 | t_k = 5  | to be inserted in A: b5, b4, b3
	// Fourth Batch | k = 4 | t_k = 11 | to be inserted in A: b11, b10, b9, b8, b7, b6, b5

	n_erased = 0;
	b_size = static_cast<int>(b.size());
	jacobsthal = getJacobsthalSequence< std::list<int> >(b_size);

	for (it_j = jacobsthal.begin(); it_j != jacobsthal.end() && b.size() != 0; it_j++)
	{
		if (*it_j >= 0 && *it_j < b_size)
		{
			it_b = b.begin();
			std::advance(it_b, *it_j - n_erased);
		}
		else
			it_b = b.end();
		while(it_b != b.begin())
		{
			--it_b;
			binaryInsertion(a, *it_b);
			it_b = b.erase(it_b);
			n_erased++;
		}
	}
	
	// Copy sorted list back to original list
	l = a;
	return (clock() - start);
}

clock_t PmergeMe::_sortDeque(std::deque<int> &d)
{
	if (d.size() < 1)
		return (0);
		
	// Start timer
	clock_t start = clock();

	int							n_erased, b_size;
	std::deque<int>				a, b, jacobsthal;
	std::deque<int>::iterator	it, it_b, it_j;

	// 1st step: Pairwise comparison - sort each pair (a[i] > b[i])
	for (it = d.begin(); it != d.end();)
	{
		int first = *it++;
		if (it == d.end())
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
	recursiveDequeSort(a, b, 0);

	// 3rd step: Insertion - 'b' is inserted into 'a' using Binary Insertion
	n_erased = 0;
	b_size = static_cast<int>(b.size());
	jacobsthal = getJacobsthalSequence< std::deque<int> >(b.size());

	for (it_j = jacobsthal.begin(); it_j != jacobsthal.end() && b.size() != 0; it_j++)
	{
		if (*it_j >= 0 && *it_j < b_size)
		{
			it_b = b.begin();
			std::advance(it_b, *it_j - n_erased);
		}
		else
			it_b = b.end();
		while(it_b != b.begin())
		{
			--it_b;
			binaryInsertion(a, *it_b);
			it_b = b.erase(it_b);
			n_erased++;
		}
	}
	
	// Copy sorted list back to original list
	d = a;
	return (clock() - start);
}

// Helper Functions ----------------------------------------------------------------

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
