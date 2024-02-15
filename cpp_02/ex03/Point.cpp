/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:06 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 18:50:24 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// CONSTRUCTORS, DESTRUCTOR AND ASSIGNMENT OPERATOR ----------------------------

Point::Point(void): _x(0), _y(0) {}
Point::Point(const Point &src): _x(src._x), _y(src._y) {}
Point::Point(const float x, const float y): _x(x), _y(y) {}
Point::~Point(void) {}

Point &Point::operator=(const Point &src)
{
	if (this != &src)
	{
		(Fixed)this->_x = src.getX();
		(Fixed)this->_y = src.getY();
	}
	return (*this);
}

// GETTERS --------------------------------------------------------------------

Fixed Point::getX(void) const { return (this->_x); }
Fixed Point::getY(void) const { return (this->_y); }
