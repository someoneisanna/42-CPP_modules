/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:17:42 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/27 09:57:47 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

#define CYAN  "\033[0;36m"
#define RED   "\033[0;31m"
#define RESET "\033[0m"

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array() : _array(new T[0]), _size(0)
		{
			std::cout << CYAN <<"Default constructor called" << RESET << std::endl;
		}

		Array(unsigned int n) : _array(new T[n]), _size(n)
		{
			std::cout << CYAN << "Parametric constructor called" << RESET << std::endl;
		}

		Array(Array const &src) : _array(new T[src._size]), _size(src._size)
		{
			std::cout << CYAN << "Copy constructor called" << RESET << std::endl;
			for (unsigned int i = 0; i < src._size; i++)
				_array[i] = src._array[i];
		}
		
		~Array()
		{
			std::cout << RED << "Destructor called" << RESET << std::endl;
			delete[] _array;
		}

		Array &operator=(Array const &src)
		{
			std::cout << CYAN << "Assignment operator called" << RESET << std::endl;
			if (this != &src)
			{
				if (this->_array)
					delete[] _array;
				if (src._size > 0)
				{
					_size = src._size;
					_array = new T[src._size];
					for (unsigned int i = 0; i < src._size; i++)
						_array[i] = src._array[i];
				}
			}
			return (*this);
		}

		T &operator[](unsigned int index)
		{
			if (index >= this->_size || this->_array == NULL)
				throw OutOfBoundsException();
			return (_array[index]);
		}

		unsigned int size() const { return (this->_size); }

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Out of bounds");
				}
		};
};

#endif
