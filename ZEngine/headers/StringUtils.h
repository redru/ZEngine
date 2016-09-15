#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

namespace zng {

	class StringUtils {

	public:
		static std::vector<std::string> zng::StringUtils::split(const std::string &s, char delim);
		static void readFile(std::string path, std::string& target);

	private:
		static void zng::StringUtils::split(const std::string &s, char delim, std::vector<std::string> &elems);

	};

}
