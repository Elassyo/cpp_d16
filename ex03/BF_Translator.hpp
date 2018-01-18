/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** BF_Translator class definition
*/

#if !defined (BF_TRANSLATOR_HPP_)
	#define BF_TRANSLATOR_HPP_

	#include <map>
	#include <string>

struct BF_Op {
	std::string code;
	char indentDiff;
};

class BF_Translator {
public:
	BF_Translator();

	int translate(std::string const &in, std::string const &out) const;
	int translate(std::ofstream &os, char c, int &ident) const;

private:
	std::map<char,BF_Op> _ops;
};

#endif /* !defined (BF_TRANSLATOR_HPP_) */
