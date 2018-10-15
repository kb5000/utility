#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using ltype = unsigned long;

class lfun
{
public:
	//make a sheet to store mut results
    lfun(ltype m)
    {
		ln.resize(m - 1, vector<ltype>(m - 1, 0));
        for (ltype i = 1; i < m; i++ )
        {
            for (ltype j = 1; j < m; j++ )
            {
                ln[i - 1][j - 1] = (i * j) % m;
            }
        }
    }
	//solve the value of lFunction
    ltype getValue(ltype k)
    {
        if (k == 0 || k > ln.size())
        {
            return 0;
        }
        ltype count = 0;
        for (auto i : ln)
            for (auto j : i)
            {
                if (j == k)
                    count++;
            }
        return count;
    }
	//print the whole sheet
    void print(bool nu)
    {
        if (nu)
        {
            auto p = ln;
            vector<ltype> line(ln[0].size() + 1);
            p.insert(p.begin(),line);
            for (ltype i = 0; i < line.size() - 1; i++ )
            {
                p[0][i] = i;
            }
            for (ltype i = 1; i < p.size(); i++ )
                p[i].insert(p[i].begin(),i);
        }
        for (auto i : ln)
        {
            for (auto j : i)
                cout << j << ' ';
            cout << endl;
        }
    }
	//solve the meta value of lFun
	ltype diffValues()
	{
		set<ltype> s;
		for (ltype i = 1; i < ln.size(); i++ )
		{
			s.insert(getValue(i));
		}
		return s.size();
	}
private:
    vector<vector<ltype>> ln;
};

int main()
{
	ltype num = 0;
	while (cin >> num)
	{
		lfun s(num);
		//cout << s.diffValues() << endl;
		//s.print(true);
		vector<ltype> sp(num);
#pragma omp parallel for
		for (ltype i = 1; i < num; i++)
		{
			sp[i - 1] = s.getValue(i);
		}
		cout << "done" << endl;
	}
	return 0;
}
