/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** Ratatouille class definition
*/

#if !defined (RATATOUILLE_HPP_)
	#define RATATOUILLE_HPP_

	#include <sstream>
	#include <string>

class Ratatouille {
public:
	Ratatouille() = default;
	Ratatouille(Ratatouille const &other);
	~Ratatouille() = default;

	Ratatouille &operator=(Ratatouille const &other);

	Ratatouille &addVegetable(unsigned char c);
	Ratatouille &addCondiment(unsigned int i);
	Ratatouille &addSpice(double d);
	Ratatouille &addSauce(std::string const &s);
	std::string kooc();

private:
	std::ostringstream _oss;
};

#endif /* !defined (RATATOUILLE_HPP_) */
