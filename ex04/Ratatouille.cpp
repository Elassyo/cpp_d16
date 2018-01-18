/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** Ratatouille class implementation
*/

#include "Ratatouille.hpp"

Ratatouille &Ratatouille::addVegetable(unsigned char c)
{
	this->_oss << c;
	return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int i)
{
	this->_oss << i;
	return *this;
}

Ratatouille &Ratatouille::addSpice(double d)
{
	this->_oss << d;
	return *this;
}

Ratatouille &Ratatouille::addSauce(std::string const &s)
{
	this->_oss << s;
	return *this;
}

std::string Ratatouille::kooc()
{
	return this->_oss.str();
}
