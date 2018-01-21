#include <cstdio>
#include <memory.h>
#define MAX(a, b) (a) > (b) ? (a) : (b)
long long dp[101];

int main(){
	int n;
	scanf("%d", &n);
	
	dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4, dp[5] = 5;
	
	for(int i = 6; i <= n; i++)
		for(int j = 2; j <= i - 3; j++)
			dp[i] = MAX(dp[i], dp[j] * (i - j - 2) + dp[j]);
	
	printf("%lld", dp[n]);
}