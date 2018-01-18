/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** Event class implementation
*/

#include "Event.hpp"

Event::Event() :
	_time(0), _event("")
{
}

Event::Event(unsigned int time, std::string const &event) :
	_time(time), _event(event)
{
}

unsigned int Event::getTime() const
{
	return (this->_time);
}

std::string const &Event::getEvent() const
{
	return (this->_event);
}

void Event::setTime(unsigned int time)
{
	this->_time = time;
}

void Event::setEvent(std::string const &event)
{
	this->_event = event;
}
