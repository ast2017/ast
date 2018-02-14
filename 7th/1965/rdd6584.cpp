#include <cstdio>
#define MAX(a, b) (a) > (b) ? (a) : (b)

int vec[1000];
int dp[1000];
// dp[i]는 vec[i] ~ vec[n - 1]까지 계산 했을 때 최댓값.

int main() {
	int n, max = 1;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &vec[i]);
		dp[i] = 1;
	}

	for (int i = n - 1; i >= 0; i--){
		for (int j = i + 1; j < n; j++)
			if (vec[i] < vec[j])
				dp[i] = MAX(dp[i], dp[j] + 1);
        max = MAX(max, dp[i]);
    }

	printf("%d", max);
}