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

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <cmath>
#include <deque>
#include <list>

#define RESET		"\033[0m"
#define PURPLE		"\033[35m"

class PmergeMe
{
	private:
		std::list<int>	_l;
		std::deque<int>	_d;

		void	_fillContainers(char **av);
		void	_sortContainers();
		clock_t	_sortList(std::list<int> &l);
		clock_t	_sortDeque(std::deque<int> &d);

	public:
		PmergeMe(void);
		PmergeMe(char **av);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &src);
};

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

void recursiveListSort(std::list<int> &a, std::list<int> &b, unsigned int i);
void recursiveDequeSort(std::deque<int> &a, std::deque<int> &b, unsigned int i);

#endif
