#include "split.hpp"
#include "slice.hpp"
#include <iostream>
#include "strp.hpp"

using namespace std;


int main()
{
	int c = 0;
	do
	{
		print("the code is %\n", c);
		c++;
		if (c == 5)
			break;
	} while(1);
	return 0;
}

