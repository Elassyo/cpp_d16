/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** EventManager class definition
*/

#if !defined (EVENT_MANAGER_HPP_)
	#define EVENT_MANAGER_HPP_

	#include <list>
	#include "Event.hpp"

class EventManager {
public:
	EventManager();
	EventManager(EventManager const &other) = default;
	~EventManager() = default;

	EventManager &operator=(EventManager const &other) = default;

	void addEvent(Event const &event);
	void removeEventsAt(unsigned int time);
	void dumpEvents() const;
	void dumpEventAt(unsigned int time) const;
	void addTime(unsigned int time);
	void addEventList(std::list<Event> const &events);

private:
	unsigned int _currentTime;
	std::list<Event> _events;
};

#endif /* !defined (EVENT_MANAGER_HPP_) */
