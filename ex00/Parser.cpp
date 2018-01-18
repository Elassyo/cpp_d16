/*
** EPITECH PROJECT, 2018
** CPP Pool Day 15
** File description:
** Parser class implementation
*/

#include <stdexcept>
#include "Parser.hpp"

void Parser::feed(std::string const &expr)
{
	size_t off = 0;
	if (!this->_operands.empty())
		this->_operators.push('+');
	while (off < expr.size())
		off += this->parse(expr, off);
	while (!this->_operators.empty()) {
		this->_operands.push(doop(this->_operators.top()));
		this->_operators.pop();
	}
}

size_t Parser::parse(std::string const &expr, size_t off)
{
	size_t parsed = 1;
	switch (expr[off]) {
	case '(': case '+': case '-': case '*': case '/': case '%':
		this->_operators.push(expr[off]);
		break;
	case ' ':
		break;
	case ')':
		while (this->_operators.top() != '(') {
			this->_operands.push(doop(this->_operators.top()));
			this->_operators.pop();
		}
		this->_operators.pop();
		break;
	default:
		this->_operands.push(std::stoi(expr.substr(off), &parsed));
	}
	return parsed;
}

long Parser::doop(char op)
{
	long right = this->_operands.top();
	this->_operands.pop();
	long left = this->_operands.top();
	this->_operands.pop();
	switch (op) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	case '%':
		return left % right;
	default:
		throw std::exception();
	}
}

int Parser::result() const
{
	if (this->_operands.empty())
		return 0;
	return this->_operands.top();
}

void Parser::reset()
{
	while (!this->_operators.empty())
		this->_operators.pop();
	while (!this->_operands.empty())
		this->_operands.pop();
}
