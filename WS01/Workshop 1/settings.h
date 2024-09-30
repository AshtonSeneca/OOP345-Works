#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <string>

namespace seneca {
	// only public data-members and no member-functions
	struct Settings {
		// Public Members

		// m_show_all as a Boolean attribute; when true, if a word has multiple definitions, all definitions should be printed on screen, 
		// otherwise only the first definition should be shown (default false).
		bool m_show_all = false;
		// m_verbose as a Boolean attribute; when true, print to screen the part-of-speech of a word if it exists (default false).
		bool m_verbose = false;
		// m_time_units as a std::string attribute; stores the time units to be used when printing duration of various operations.
		// Possible values are seconds, milliseconds, microseconds, nanoseconds (default nanoseconds).
		std::string m_time_units = "nanoseconds";
	};

	// Global variable declaration
	extern Settings g_settings;
}
#endif // !SENECA_SETTINGS_H