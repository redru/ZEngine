#include "StringUtils.h"

void zng::StringUtils::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

void zng::StringUtils::readFile(std::string path, std::string& target) {
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	target = buffer.str();
}

std::vector<std::string> zng::StringUtils::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	zng::StringUtils::split(s, delim, elems);
	return elems;
}
