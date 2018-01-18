/*
** EPITECH PROJECT, 2018
** CPP Pool Day
** File description:
** DomesticKoala class implementation
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action) :
	_actions(256, nullptr), _koalaAction(action)
{
}

std::vector<methodPointer_t> const &DomesticKoala::getActions() const
{
	return this->_actions;
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
	this->_koalaAction = action;
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
	this->_actions[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
	this->_actions[command] = nullptr;
}

void DomesticKoala::doAction(unsigned char command, std::string const &param)
{
	if (this->_actions[command])
		(this->_koalaAction.*this->_actions[command])(param);
}
