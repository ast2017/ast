#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define max(a,b) a > b ? a : b

int main() {
	int n;
	int ar[1001] = {0,};
	int dp[1001] = {0,};
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &ar[i]);


	int sol = 1;
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(ar[j] < ar[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if(dp[i] != 1) sol = max(dp[i], sol);
	}

	printf("%d\n", sol);
	return 0;
}