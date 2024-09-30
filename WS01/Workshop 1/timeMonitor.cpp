#include "timeMonitor.h"


namespace seneca {
	TimeMonitor::TimeMonitor(const char* name) {
		m_name = name;
	}

	TimeMonitor::~TimeMonitor() {
	}

	void TimeMonitor::startEvent(const char* name) {
		m_name = name;
		m_timeStart = std::chrono::high_resolution_clock::now();
	}

	Event TimeMonitor::stopEvent() {
		m_timeEnd = std::chrono::high_resolution_clock::now();
		Event event(m_name, std::chrono::duration_cast<std::chrono::nanoseconds>(m_timeEnd - m_timeStart));
		m_events[m_cnt++] = event;
		return event;
	}
}
