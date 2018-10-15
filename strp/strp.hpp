#include <cstdio>
#include <string>
#include "slice.hpp"
#include "split.hpp"

namespace std
{
std::string to_string(std::string s)
{
	return s;
}
}

std::string __split_char = "%";
std::string __split_char_self = "%%";

template<typename T>
std::string combine(std::string str, T cont)
{
	auto fstr = splitFirst(str, __split_char, {__split_char_self});
	std::string s = fstr[0] + std::to_string(cont) + fstr[1];
	return s;
}

template<typename T, typename... Args>
std::string combine(std::string str, T cont, Args... args)
{
	auto fstr = splitFirst(str, __split_char, {__split_char_self});
	std::string s = fstr[0] + std::to_string(cont) + fstr[1];
	return combine(s, args...);
}

std::string combine(std::string str)
{
	return str;
}

template<typename... Args>
void print(std::string formt, Args... args)
{
	std::string cache = combine(formt, args...);
	std::printf(cache.c_str());
}

void splitChar(std::string sc)
{
	__split_char = sc;
	__split_char_self = sc + sc;
}

void splitChar(std::string sc, std::string scself)
{
	__split_char = sc;
	__split_char_self = scself;
}





