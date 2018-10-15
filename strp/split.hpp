#pragma once

#include <string>
#include <vector>


std::vector<std::string> split(const std::string& str, const std::string& chr)
{
	std::vector<std::string> s;
	auto beg = str.cbegin();
	std::size_t lastPos = 0;
	bool isFind = false;
	for (std::size_t i = 0; i < str.size() - chr.size() + 1; i++)
	{
		std::string tmp(beg + i, beg + i + chr.size());
		if (tmp == chr)
		{
			s.push_back(std::string(beg + lastPos, beg + i));
			lastPos = i + chr.size();
			i = lastPos - 1;
			isFind = true;
		}
	}
	if (!isFind)
	{
		s.push_back(str);
	}
	return s;
}

std::vector<std::string> splitFirst(const std::string& str, const std::string& chr)
{
	std::vector<std::string> s;
	auto beg = str.cbegin();
	std::size_t lastPos = 0;
	bool isFind = false;
	for (std::size_t i = 0; i < str.size() - chr.size() + 1; i++)
	{
		std::string tmp(beg + i, beg + i + chr.size());
		if (tmp == chr)
		{
			s.push_back(std::string(beg + lastPos, beg + i));
			s.push_back(std::string(beg + i + chr.size(), str.cend()));
			isFind = true;
			break;
		}
	}
	if (!isFind)
	{
		s.push_back(str);
	}
	return s;
}

std::vector<std::string> split(const std::string& str, const std::string& chr, const std::vector<std::string>& notin)
{
	std::vector<std::string> s;
	auto beg = str.cbegin();
	std::size_t lastPos = 0;
	bool isFind = false;
	std::string accu;
	for (std::size_t i = 0; i < str.size() - chr.size() + 1; i++)
	{
		bool isRepeat = false;
		std::string tmp(beg + i, beg + i + chr.size());
		if (tmp == chr)
		{
			for (auto j : notin)
			{
				std::string tm(beg + i, beg + i + j.size());
				if (tm == j)
				{
					isRepeat = true;
					accu += chr;	
				}	
			}
			if (!isRepeat)
			{
				s.push_back(std::string(beg + lastPos, beg + i));
				s[s.size() - 1] += accu;
				accu.clear();
				lastPos = i + chr.size();
				i = lastPos - 1;
				isFind = true;
			}
		}
	}
	if (!isFind)
	{
		s.push_back(str);
	}
	return s;
}


std::vector<std::string> splitFirst(const std::string& str, const std::string& chr, const std::vector<std::string>& notin)
{
	std::vector<std::string> s;
	auto beg = str.cbegin();
	std::size_t lastPos = 0;
	bool isFind = false;
	std::string accu;
	for (std::size_t i = 0; i < str.size() - chr.size() + 1; i++)
	{
		bool isRepeat = false;
		std::string tmp(beg + i, beg + i + chr.size());
		if (tmp == chr)
		{
			for (auto j : notin)
			{
				std::string tm(beg + i, beg + i + j.size());
				if (tm == j)
				{
					isRepeat = true;
					accu += chr;	
				}	
			}
			if (!isRepeat)
			{
				s.push_back(std::string(beg + lastPos, beg + i));
				s[s.size() - 1] += accu;
				accu.clear();
				s.push_back(std::string(beg + i + chr.size(), str.cend()));
				isFind = true;
				break;
			}
		}
	}
	if (!isFind)
	{
		s.push_back(str);
	}
	return s;
}
