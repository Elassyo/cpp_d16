/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** Parser class definition
*/

#if !defined (PARSER_HPP_)
	#define PARSER_HPP_

	#include <string>
	#include <stack>

class Parser {
public:
	void feed(std::string const &expr);
	int result() const;
	void reset();

private:
	size_t parse(std::string const &expr, size_t off);
	long doop(char op);

	std::stack<char> _operators;
	std::stack<long> _operands;
};

#endif /* !defined (PARSER_HPP_) */
