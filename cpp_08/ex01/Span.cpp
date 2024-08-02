/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:22:45 by ataboada          #+#    #+#             */
/*   Updated: 2024/08/02 09:50:00 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors, Destructor & Assignment Operator Overload ---------------------

Span::Span() : _N(0) {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(Span const &src) { *this = src; }

Span::~Span() {}

Span &Span::operator=(Span const &src)
{
	this->_N = src._N;
	this->_storage = src._storage;
	return *this;
}

// Member Functions ------------------------------------------------------------

void	Span::addNumber(int n)
{
	if (this->_storage.size() < this->_N)
		this->_storage.push_back(n);
	else
		throw Span::StorageFullException();
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_storage.size() + std::distance(begin, end) <= this->_N)
		this->_storage.insert(this->_storage.end(), begin, end);
	else
		throw Span::StorageFullException();
}

int		Span::shortestSpan()
{
	if (this->_storage.size() < 2)
		throw Span::NoSpanException();

	std::vector<int> cpy = this->_storage;
	std::sort(cpy.begin(), cpy.end());

	int shortest = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = cpy.begin(); it != cpy.end() - 1; it++)
	{
		int span = *(it + 1) - *it;
		if (span < shortest)
			shortest = span;
	}
	return (shortest);
}

int		Span::longestSpan()
{
	if (this->_storage.size() < 2)
		throw Span::NoSpanException();
	std::vector<int>::iterator min = std::min_element(this->_storage.begin(), this->_storage.end());
	std::vector<int>::iterator max = std::max_element(this->_storage.begin(), this->_storage.end());
	return (*max - *min);
}

void	Span::printStorage()
{
	std::cout << "Storage: ";
	for (std::vector<int>::iterator it = this->_storage.begin(); it != this->_storage.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Exceptions ------------------------------------------------------------------

const char *Span::StorageFullException::what() const throw()
{
	return ("Storage is full!");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("No span to find!");
}
