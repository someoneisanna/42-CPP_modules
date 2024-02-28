/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:06:48 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:12 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <stack>
#include <list>
#include <deque>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack() : std::stack<T, C>() {}
		MutantStack(MutantStack const &src) : std::stack<T, C>(src) {}
		virtual ~MutantStack() {}

		MutantStack &operator=(MutantStack const &src)
		{
			if (this != &src)
				std::stack<T, C>::operator=(src);
			return (*this);
		}

		typedef typename C::iterator iterator;
		iterator begin() { return std::stack<T, C>::c.begin(); }
		iterator end() { return std::stack<T, C>::c.end(); }
};

#endif
