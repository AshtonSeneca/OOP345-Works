#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <iostream>
#include <chrono>
#include <string>

namespace seneca
{
	class Event {
		// name of the event
		std::string m_name;
		// duration of the event
		std::chrono::nanoseconds m_duration;
	public:
		// default constructor
		Event();
		// constructor with parameters
		Event(const char* name, const std::chrono::nanoseconds& duration);
		// friend helper
		friend std::ostream& operator<<(std::ostream& out, const Event& event);
	};
}
#endif // SENECA_EVENT_H
