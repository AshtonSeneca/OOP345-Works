#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <iomanip>
#include "event.h"

namespace seneca
{
	// measures the duration of various operations/events
	class TimeMonitor
	{
		// time point when the event started
		std::chrono::high_resolution_clock::time_point m_timeStart;
		// time point when the event ended
		std::chrono::high_resolution_clock::time_point m_timeEnd;
		// name of the event
		const char* m_name = nullptr;
		// maximum number of events that can be recorded
		static const int MAX_EVENTS = 10;
		// number of events recorded
		int m_cnt = 0;
		// collection of events
		Event m_events[MAX_EVENTS];
	public:
		// default constructor
		TimeMonitor() {};
		// constructor with parameters
		TimeMonitor(const char* name);
		// destructor
		~TimeMonitor();
		// start a new event
		void startEvent(const char* name);
		// stop the current event
		Event stopEvent();

	};
}
#endif // !SENECA_TIMEMONITOR_H