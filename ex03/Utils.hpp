#include <string>

class Utils {
	public: 
		static std::string trim(std::string str)
		{
			std::size_t start = str.find_first_not_of(" \t\n\r");
			std::size_t end = str.find_last_not_of(" \t\n\r");
			if(start == std::string::npos || end == std::string::npos)
				return "";
			return str.substr(start, end - start + 1);
		}
};
