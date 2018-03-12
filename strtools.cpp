#include "strtools.h"

std::vector<std::string> str::explode(std::string const &s, char delim, bool trim)
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		if (trim)
		{
			str::trim(token);
		}
		result.push_back(std::move(token));
	}
	return result;
}
