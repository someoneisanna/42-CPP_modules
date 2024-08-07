/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:25:02 by ataboada          #+#    #+#             */
/*   Updated: 2024/08/06 16:39:43 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

class RPN
{
	private:
		std::stack<int>		_stack;
		std::string			_expression;
		int					_result;

	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &src);
		~RPN();

		RPN &operator=(const RPN &src);

		int		_parseExpression();
		int		_solveOperand(char op);
		void	_printResult();
};

#endif
