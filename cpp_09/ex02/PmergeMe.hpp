 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:26:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/24 10:26:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// Includes --------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <deque>
#include <cmath>

// Defines ---------------------------------------------------------------------

#define RESET		"\033[0m"
#define PURPLE		"\033[35m"

// Class -----------------------------------------------------------------------

class PmergeMe
{
	private:
		std::vector<int>	_l;
		std::deque<int>		_d;

		void	_fillContainers(char **av);
		void	_sortContainers();
		clock_t	_sortVector(std::vector<int> &l);
		clock_t	_sortDeque(std::deque<int> &d);

	public:
		PmergeMe(void);
		PmergeMe(char **av);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &src);
};

// Template Functions ----------------------------------------------------------

template <typename Container>
Container getJacobsthalSequence(int n)
{
	Container jacobsthal;
	for (int k = 1; k <= n; k++)
	{
		int t_k = (std::pow(2, k + 1) + std::pow(-1, k))/3;
		jacobsthal.push_back(t_k);
	}
	return (jacobsthal);
}

template <typename Container>
void binaryInsertion(Container &c, int n)
{
	typename Container::iterator it = std::lower_bound(c.begin(), c.end(), n);
	c.insert(it, n);
}

template <typename Container>
void merge(Container& a, Container& b, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	Container L1(n1), R1(n2), L2(n1), R2(n2);
	
	for (int i = 0; i < n1; i++)
	{
		L1[i] = a[left + i];
		L2[i] = b[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R1[j] = a[mid + 1 + j];
		R2[j] = b[mid + 1 + j];
	}
	
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L1[i] <= R1[j])
		{
			a[k] = L1[i];
			b[k] = L2[i++];
		}
		else
		{
			a[k] = R1[j];
			b[k] = R2[j++];
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L1[i];
		b[k] = L2[i++];
		k++;
	}
	while (j < n2)
	{
		a[k] = R1[j];
		b[k] = R2[j++];
		k++;
	}
}

template <typename Container>
void recursiveSort(Container &a, Container &b, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	recursiveSort(a, b, left, mid);
	recursiveSort(a, b, mid + 1, right);
	merge(a, b, left, mid, right);
}

template <typename Container>
void printContainer(Container &c)
{
	typename Container::iterator it = c.begin();
	while (it != c.end())
	{
		std::cout << *it;
		it++;
		if (it != c.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

#endif
