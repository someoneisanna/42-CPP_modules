/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:22:50 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/27 15:41:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	_storage;
		unsigned int		_N;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &src);

		void	addNumber(int n);
		void	addNumbers();
		int		shortestSpan();
		int		longestSpan();
		void	printStorage();

		class StorageFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
