/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:28 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/19 15:43:14 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain &operator=(Brain const &src);
};

#endif
