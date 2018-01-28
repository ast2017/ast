#include <iostream>
#include <math.h>
using namespace std;

int n, r, c;

int zfunc(int z, int x, int y, int count)
{
	int ax[] = { 0, 0, 1, 1 };
	int ay[] = { 0, 1, 0, 1 };

	for (int i = 0; i < 4; i++)
	{
		int p = pow(2, z-1);
		int pp = pow(4, z-1);
		if (x + ax[i] * p <= r && r < x + ax[i] * p + p
			&& y + ay[i] * p <= c && c < y + ay[i] * p + p)
		{
			if (z == 1)
			{
				return count + p * i;
			}
			else
			{
				return zfunc(z - 1, x + ax[i] * p, y + ay[i] * p, count + pp * i);
			}
		}
	}

	return 0;
}

int main()
{
	scanf("%d %d %d", &n, &r, &c);

	printf("%d\n", zfunc(n, 0, 0, 0));

	return 0;
}
