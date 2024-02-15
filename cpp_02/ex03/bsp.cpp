/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:18 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:45 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	determinant_sign(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	return (((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)).toInt());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed point_x = point.getX();
	Fixed point_y = point.getY();

	int d1 = determinant_sign(point_x, point_y, a.getX(), a.getY(), b.getX(), b.getY());
	int d2 = determinant_sign(point_x, point_y, b.getX(), b.getY(), c.getX(), c.getY());
	int d3 = determinant_sign(point_x, point_y, c.getX(), c.getY(), a.getX(), a.getY());

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
