/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:25:21 by ataboada          #+#    #+#             */
/*   Updated: 2024/02/28 20:08:53 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors, Destructors and Assignment Overload --------------------------------

RPN::RPN() : _expression(""), _result(0) {}

RPN::RPN(std::string expression) : _expression(expression), _result(0)
{
	_parseExpression();
	_printResult();
}

RPN::RPN(const RPN &src) : _expression(src._expression), _result(src._result)
{
	_parseExpression();
	_printResult();
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_stack = src._stack;
		this->_expression = src._expression;
		_parseExpression();
		_printResult();
	}
	return (*this);
}

// Member Functions ------------------------------------------------------------------

void RPN::_parseExpression()
{
	std::string s = this->_expression;

	if (s.empty())
	{
		std::cerr << "Error: Empty expression" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			continue;
		if (std::isdigit(s[i]))
			this->_stack.push(s[i] - '0');
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (this->_stack.size() < 2)
			{
				std::cerr << "Error: Invalid expression" << std::endl;
				return;
			}
			_solveOperand(s[i]);
		}
		else
		{
			std::cerr << "Error: Invalid character" << std::endl;
			return;
		}
	}
}

void RPN::_solveOperand(char op)
{
	int a = this->_stack.top();
	this->_stack.pop();
	int b = this->_stack.top();
	this->_stack.pop();

	switch (op)
	{
		case '+':
			this->_stack.push(b + a);
			break;
		case '-':
			this->_stack.push(b - a);
			break;
		case '*':
			this->_stack.push(b * a);
			break;
		case '/':
			this->_stack.push(b / a);
			break;
	}
}

void RPN::_printResult()
{
	if (this->_stack.size() != 1)
	{
		std::cerr << "Error: Invalid expression" << std::endl;
		return;
	}
	this->_result = this->_stack.top();
	std::cout << this->_result << std::endl;
}
