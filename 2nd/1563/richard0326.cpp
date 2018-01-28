#include <iostream>
using namespace std;

int n;
int d[2][3][1001];
int go(int len, int l, int a);

int main()
{
	scanf("%d", &n);

	printf("%d\n", go(0, 0, 0));
	return 0;
}

int go(int len, int l, int a)
{
	if (len >= n)
		return 1;

	int count = 0;

	if (l == 0) {
		if (d[l + 1][0][len + 1] != 0)
		{
			count += d[l + 1][0][len + 1];
		}
		else
		{
			count += go(len + 1, l + 1, 0);
		}
	}
	if (a != 2) { 
		if (d[l][a + 1][len + 1] != 0)
		{
			count += d[l][a + 1][len + 1];
		}
		else
		{
			count += go(len + 1, l, a + 1);
		}
	}

	if (d[l][0][len + 1] != 0)
	{
		count += d[l][0][len + 1];
	}
	else
	{
		count += go(len + 1, l, 0);
	}
	d[l][a][len] = count % 1000000;

	return d[l][a][len];
}
