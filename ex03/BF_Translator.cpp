/*
** EPITECH PROJECT, 2018
** CPP Pool Day
** File description:
** BF_Translator class implementation
*/

#include <cctype>
#include <fstream>
#include "BF_Translator.hpp"

BF_Translator::BF_Translator() :
	_ops {
		{ '>', { "++ptr;", 0 }},
		{ '<', { "--ptr;", 0 }},
		{ '+', { "++*ptr;", 0 }},
		{ '-', { "--*ptr;", 0 }},
		{ '.', { "putchar(*ptr);", 0 }},
		{ ',', { "*ptr = getchar();", 0 }},
		{ '[', { "while (*ptr) {", 2 }},
		{ ']', { "}", -2 }}
	}
{
}

int BF_Translator::translate(std::string const &in, std::string const &out)
	const
{
	std::ifstream inf(in);
	std::ofstream outf(out);
	if (!inf || !outf)
		return -1;
	outf << "#include <stdio.h>\n#include <stdlib.h>\n\nint main()\n{\n"
		"  char *mem = calloc(1, 61440);\n  char *ptr = mem;\n";
	char c;
	int ident = 2;
	while (inf.get(c)) {
		if (std::isspace(c))
			continue;
		auto it = this->_ops.find(c);
		if (it == this->_ops.end())
			return 1;
		outf << std::string(ident, ' ') << it->second.code << std::endl;
		ident += it->second.indentDiff;
	}
	outf << "  free(mem);\n  return 0;\n}\n";
	return 0;
}
