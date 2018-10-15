#include <array>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using lt = array<int, 5>;
//using lt = vector<int>;
/*
 * a b c
 * d   e
 *
 * lf:
 * b d c
 * a   e
 *
 * rf:
 * a c e
 * d   b
 */
//rotate 
lt left(lt tar)
{
	lt res = {
		tar[1], tar[3], tar[2], tar[0], tar[4]
	};
	return res;
}

lt right(lt tar)
{
	lt res = {
		tar[0], tar[2], tar[4], tar[3], tar[1]
	};
	return res;
}

int rever(lt tar)
{
	int c = 0;
	for (size_t i = 0; i < tar.size(); i++)
	{
		for (size_t j = i + 1; j < tar.size(); j++)
		{
			if (tar[j] < tar[i])
				c++;
		}
	}
	return c;
}

int count(set<lt>& s, lt tar, bool fistRun = true)
{
	auto lf = left(tar);
	auto rf = right(tar);
	bool lft = any_of(s.cbegin(), s.cend(), [lf](lt v){
				return v == lf;
			});
	bool rft = any_of(s.cbegin(), s.cend(), [rf](lt v){
				return v == rf;
			});
	if (lft && rft)
		return 1;
	if (lft && !rft)
	{
		s.insert(rf);
		return 1 + count(s, rf, false);
	}
	if (!lft && rft)
	{
		s.insert(lf);
		return 1 + count(s, lf, false);
	}
	if (!lft && !rft)
	{
		if (fistRun)
			s.insert(tar);
		s.insert(lf);
		s.insert(rf);
		return 1 + count(s, lf, false) + count(s, rf, false);
	}
	return 0; //the complier says it may reach non-void, make it happy.
}

int printL(lt l)
{
	for (auto i : l)
		cout << i;
	return 0;
}

int countSay(set<lt>& s, lt tar, bool fistRun = true)
{
	auto lf = left(tar);
	auto rf = right(tar);
	bool lft = any_of(s.cbegin(), s.cend(), [lf](lt v){
				return v == lf;
			});
	bool rft = any_of(s.cbegin(), s.cend(), [rf](lt v){
				return v == rf;
			});
	if (lft && rft)
		return 1;
	if (lft && !rft)
	{
		s.insert(rf);
		cout << "rf ";
		printL(rf);
		cout << " from ";
		printL(tar);
		cout << " with rev " << rever(rf) << endl;
		return 1 + countSay(s, rf, false);
	}
	if (!lft && rft)
	{
		s.insert(lf);
		cout << "lf ";
		printL(lf);
		cout << " from ";
		printL(tar);
		cout << " with rev " << rever(lf) << endl;
		return 1 + countSay(s, lf, false);
	}
	if (!lft && !rft)
	{
		if (fistRun)
		{
			s.insert(tar);
			cout << "   ";
			printL(tar);
			cout << " with rev " << rever(tar) <<endl;
		}
		s.insert(lf);
		s.insert(rf);
		cout << "lf ";
		printL(lf);
		cout << " from ";
		printL(tar);
		cout << " with rev " << rever(lf) << endl;

		auto a = countSay(s, lf, false);

		cout << "rf ";
		printL(rf);
		cout << " from ";
		printL(tar);
		cout << " with rev " << rever(rf) << endl;
		auto b = countSay(s, rf, false);
		return 1 + a + b;
	}
	return 0; //the complier says it may reach non-void, make it happy.
}

int main()
{
	set<lt> s;
	lt a = {1, 2, 3, 4, 5};
	cout << countSay(s, a) << endl;
}



