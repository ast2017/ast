#include <iostream>
#include <string.h>
using namespace std;

long long length[100001];
long long fuel[100001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n - 1; i++)
	{
		scanf("%lld", &length[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &fuel[i]);
	}

	long long ans = 0;
	long long minFuelCost = 0;
	for (int i = 1; i < n; i++)
	{
		if (minFuelCost > fuel[i] || minFuelCost == 0)
		{
			minFuelCost = fuel[i];
		}

		ans += minFuelCost * length[i];
	}

	printf("%lld\n", ans);
	return 0;
}
