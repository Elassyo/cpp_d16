/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** EventManager class implementation
*/

#include <iostream>
#include "EventManager.hpp"

EventManager::EventManager() :
	_currentTime(0), _events()
{
}

void EventManager::addEvent(Event const &event)
{
	if (event.getTime() < this->_currentTime)
		return;
	auto it = this->_events.begin();
	while (it != this->_events.end() &&
		it->getTime() <= event.getTime())
		it++;
	this->_events.insert(it, event);
}

void EventManager::removeEventsAt(unsigned int time)
{
	auto it = this->_events.begin();
	while (it != this->_events.end()) {
		auto next = std::next(it);
		if (it->getTime() == time)
			this->_events.erase(it);
		it = next;
	}
}

void EventManager::dumpEvents() const
{
	auto it = this->_events.begin();
	while (it != this->_events.end()) {
		std::cout << it->getTime() << ": " << it->getEvent() <<
			std::endl;
		it++;
	}
}

void EventManager::dumpEventAt(unsigned int time) const
{
	auto it = this->_events.begin();
	while (it != this->_events.end() &&
		it->getTime() < time)
		it++;
	while (it != this->_events.end() &&
		it->getTime() == time) {
		std::cout << it->getTime() << ": " << it->getEvent() <<
			std::endl;
		it++;
	}
}

void EventManager::addTime(unsigned int time)
{
	this->_currentTime += time;
	auto it = this->_events.begin();
	while (it != this->_events.end() &&
		it->getTime() <= this->_currentTime) {
		auto next = std::next(it);
		std::cout << it->getEvent() << std::endl;
		this->_events.erase(it);
		it = next;
	}
}

void EventManager::addEventList(std::list<Event> const &events)
{
	auto it = events.begin();
	while (it != events.end())
		this->addEvent(*it++);
}
