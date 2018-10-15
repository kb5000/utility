#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

void itocs(int num, char* c, int base)
{
	short sign = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	int length = 0;
	int n = num;
	while (n != 0)
	{
		length++;
		n /= base;
	}
	for (int i = 0; i < length; i++)
	{
		c[length - i - 1] = num % base + '0';
		num /= base;
	}
	c[length] = '\0';
}

int main()
{
	char* c = (char*)malloc(20);
	itocs(2432, c, 10);
	printf("%s",c);
}
