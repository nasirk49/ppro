#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

namespace str
{
	// trim from start (in place)
	static inline void ltrim(std::string &s)
	{
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
			return !std::isspace(ch); }));
	}

	// trim from end (in place)
	static inline void rtrim(std::string &s)
	{
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch); }).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(std::string &s)
	{
		ltrim(s);
		rtrim(s);
	}

	std::vector<std::string> explode(std::string const &s, char delim, bool trim = false);

} // str