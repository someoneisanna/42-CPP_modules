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

void printList(std::list<int> l);
void printDeque(std::deque<int> d);
void recursiveListSort(std::list<int> &a, std::list<int> &b, unsigned int i);
void recursiveDequeSort(std::deque<int> &a, std::deque<int> &b, unsigned int i);

#endif
