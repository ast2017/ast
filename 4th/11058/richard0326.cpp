#include <iostream>
using namespace std;

int n;
long long dp[101];

long long MAX(long long a, long long b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int main()
{
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for (int i = 4; i <= n; i++)
	{
		int l = 2;
		long long maxV = dp[i - 1] + 1;

		// 4번 ctrl + v 까지가는데 3번이 걸림.
		for (int k = i - 3; k >= 1; k--)
		{
			maxV = MAX(maxV, dp[k] * l);
			l++; // 붙이기 회수
		}
		dp[i] = maxV;
	}

	printf("%lld\n", dp[n]);

	return 0;
}
