/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** DomesticKoala class definition
*/

#if !defined (DOMESTIC_KOALA_HPP_)
	#define DOMESTIC_KOALA_HPP_

	#include <string>
	#include <vector>
	#include "KoalaAction.hpp"

typedef void (KoalaAction::*methodPointer_t)(std::string const &);

class DomesticKoala {
public:
	DomesticKoala(KoalaAction &action);
	DomesticKoala(DomesticKoala const &other) = default;
	~DomesticKoala() = default;

	DomesticKoala &operator=(DomesticKoala const &other) = default;

	std::vector<methodPointer_t> const &getActions() const;
	void setKoalaAction(KoalaAction &action);

	void learnAction(unsigned char command, methodPointer_t action);
	void unlearnAction(unsigned char command);
	void doAction(unsigned char command, std::string const &param);

private:
	std::vector<methodPointer_t> _actions;
	KoalaAction &_koalaAction;
};

#endif /* !defined (DOMESTIC_KOALA_HPP_) */
