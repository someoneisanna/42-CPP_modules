/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:24:30 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/15 20:14:08 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

// COLORS ---------------------------------------------------------------------

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define BOLD		"\033[1m"

// CLASS DEFINITION ------------------------------------------------------------

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(void);
		Point(const Point &src);
		Point(const float x, const float y);
		~Point(void);

		Point &operator=(const Point &src);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
