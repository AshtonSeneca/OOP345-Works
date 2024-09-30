#include "event.h"
#include "settings.h"
namespace seneca 
{

// sets the default values for the current instance
	Event::Event() : m_name(""), m_duration(std::chrono::nanoseconds(0)) {}
	
	// initializes the current instance with the values of the parameters
	Event::Event(const char* name, const std::chrono::nanoseconds& duration) : m_name(name), m_duration(duration) {}

	// friend helper
	std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		//COUNTER: EVENT_NAME->DURATION TIME_UNITS
		
		static int counter = 0;

		// right align the output
		os.setf(std::ios::right);
		// local variable that remains in memory for the lifetime of the program
		// width of the field is 2
		os.width(2);
		// print the counter that holds the number of times that this operator has been called
		os << ++counter << ": ";

		// right aligned field of size 40 with the name of the event
		os.width(40);
		os << event.m_name << " -> ";

		// TIME_UNITS a string representing the time units for displayed values
		std::string time_units = g_settings.m_time_units;
		
		if (g_settings.m_time_units == "seconds")
		{
			os.width(2);
			os << std::chrono::duration_cast<std::chrono::seconds>(event.m_duration).count();
			os << time_units;
		}
		else if (g_settings.m_time_units == "milliseconds")
		{
			os.width(5);
			os << std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration).count();
			os << time_units;
		}
		else if (g_settings.m_time_units == "microseconds")
		{
			os.width(8);
			os << std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration).count();
			os << time_units;
		}
		else if (g_settings.m_time_units == "nanoseconds")
		{
			os.width(11);
			os << event.m_duration.count();
			os << time_units;
			
		}

		return os;
	}
}