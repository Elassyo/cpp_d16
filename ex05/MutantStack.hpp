/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** MutantStack class definition
*/

#if !defined (MUTANT_STACK_HPP_)
	#define MUTANT_STACK_HPP_

	#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	class iterator : public std::deque<T>::iterator {
	public:
		iterator(typename std::deque<T>::iterator const &it) :
			std::deque<T>::iterator(it)
		{
		}
	};

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}
};

#endif /* !defined (MUTANT_STACK_HPP_) */
