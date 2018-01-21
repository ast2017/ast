#include<iostream>
using namespace std;

int a[11];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	int value = k;
	int ans = 0;
	int big = n;
	while (big != 0 && value != 0)
	{
		if (value >= a[big])
		{
			ans += value / a[big];
			value = value % a[big];
		}
		
		big--;
	}

	printf("%d\n", ans);
}
