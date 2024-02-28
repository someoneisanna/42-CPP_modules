/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:25:02 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/28 20:02:00 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

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

		void	_parseExpression();
		void	_solveOperand(char op);
		void	_printResult();
};

#endif
