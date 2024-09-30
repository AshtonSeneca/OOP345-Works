#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "event.h"

namespace seneca
{
	class Logger
	{
		// dynamically allocated collection of events in the form of an array
		Event* m_events = nullptr;
		// number of events stored in the logger
		size_t m_size = 0;
		// capacity of the array
		size_t m_capacity = 0;
	public:
		// default constructor
		Logger(){};
		// disable copy operations
		Logger(const Logger&) = delete;
		// disable copy operations
		Logger& operator=(const Logger&) = delete;
		
		// move operations
		Logger(Logger&& src) noexcept;
		// move operations
		Logger& operator=(Logger&& src) noexcept;

		// destructor
		~Logger();

		// add to the array a copy of the event received as a parameter (resize the array if necessary)
		void addEvent(const Event& event);

		// print to screen all the events stored in the logger in the format:
		friend std::ostream& operator<<(std::ostream& out, const Logger& logger);
	};
}

#endif // !
