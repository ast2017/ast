#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define mod 1000000007

//C0 = 1
//C1 = C0*C0
//C2 = C0*C1 + C1*C0
//C3 = C0*C2 + C1*C1 + C2*C0
//C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0

int dp[2555];
int main() {
	int n, t; scanf("%d", &t);
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= 2500; i++) {
		for(int j = 0; j < i; j++) {
			dp[i] = (dp[i] + (long long)dp[j] * dp[i - j - 1]) % mod;
		}
	}

	while(t--) {
		scanf("%d", &n);
		printf("%d\n", n % 2 == 0 ? dp[n / 2] : 0);
	}
	return 0;
}
