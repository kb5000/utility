#pragma once

#include <string>
#include <vector>

class slice
{
public:
	slice(std::string s) :str(s)
	{}
	std::string operator()(long beg, long end, long step = 1)
	{
		std::string tem;
		if (step > 0 && beg < end)
		{
			if ((beg >= 0 && beg < str.size() && end <= str.size()) || (beg < 0 && str.size() >= -beg && str.size() >= -end - 1))
			{
				for (long i = beg; i < end; i += step)
				{
					if (i >= 0)
					{
						tem += str[i];
					}
					if (i < 0)
					{
						tem += str[str.size() - static_cast<unsigned long>(-i)];
					}
				}
			}
		}
		if (step < 0 && beg > end)
		{
			if ((beg >= -1 && (beg < str.size() || beg == -1) && end <= str.size()) || (beg < 0 && str.size() >= -beg && str.size() >= -end - 1))
			{
				for (long i = beg; i > end; i += step)
				{
					if (i >= 0)
					{
						tem += str[i];
					}
					if (i < 0)
					{
						tem += str[str.size() - static_cast<unsigned long>(-i)];
					}
				}
			}
		}
		return tem;
	}
private:
	std::string str;
};

