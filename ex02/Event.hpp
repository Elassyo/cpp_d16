/*
** EPITECH PROJECT, 2018
** CPP Pool Day 16
** File description:
** Event class definition
*/

#if !defined (EVENT_HPP_)
	#define EVENT_HPP_

	#include <string>

class Event {
public:
	Event();
	Event(unsigned int time, std::string const &event);
	Event(Event const &other) = default;
	~Event() = default;

	Event &operator=(Event const &other) = default;

	unsigned int getTime() const;
	std::string const &getEvent() const;
	void setTime(unsigned int time);
	void setEvent(std::string const &event);

private:
	unsigned int _time;
	std::string _event;
};

#endif /* !defined (EVENT_HPP_) */
