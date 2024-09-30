#include "logger.h"


/*
Public Members
default constructor
destructor
move operations
void addEvent(const Event& event): add to the array a copy of the event received as a parameter (resize the array if necessary).
Friend Helpers
operator<<: print to screen all the events stored in the logger in the format:

EVENT<endl>
EVENT<endl>
...
*/

namespace seneca {
	Logger::Logger(Logger&& src) noexcept
	{
		m_events = src.m_events;
		m_size = src.m_size;
		m_capacity = src.m_capacity;
		src.m_events = nullptr;
		src.m_size = 0;
		src.m_capacity = 0;
	}

	Logger& Logger::operator=(Logger&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_events;
			m_events = src.m_events;
			m_size = src.m_size;
			m_capacity = src.m_capacity;
			src.m_events = nullptr;
			src.m_size = 0;
			src.m_capacity = 0;
		}
		return *this;
	}

	// destructor
	Logger::~Logger()
	{
		delete[] m_events;
	}

	// add to the array a copy of the event received as a parameter (resize the array if necessary)
	void Logger::addEvent(const Event& event)
	{
		// resize the array if necessary
		if (m_size == m_capacity)
		{
			// create a new array with one more capacity
			Event* temp = new Event[m_capacity + 1];
			// copy the elements from the old array to the new array
			for (size_t i = 0; i < m_size; i++)
			{
				// copy the elements
				temp[i] = m_events[i];
			}
			// delete the old array
			delete[] m_events;
			// assign the new array to the old array
			m_events = temp;
			// increase the capacity
			m_capacity++;
		}
		// add the event to the array
		m_events[m_size++] = event;
	}

	// print to screen all the events stored in the logger in the format:
	std::ostream& operator<<(std::ostream& out, const Logger& logger)
	{
		for (size_t i = 0; i < logger.m_size; i++)
		{
			out << logger.m_events[i] << std::endl;
		}
		return out;
	}
}