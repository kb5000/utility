#include <thread>
#include <cstdlib>
#include <fstream>
#include <cstdio>

using namespace std;

double getTemp()
{
	ifstream ifs("/sys/class/thermal/thermal_zone0/temp");
	int t = 0;
	ifs >> t;
	ifs.close();
	return static_cast<double>(t);
}

int main()
{
	while (true)
	{
		system("clear");
		printf("%.2lf ℃\n", getTemp());
		this_thread::sleep_for(1s);
	}
	return 0;
}
