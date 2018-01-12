#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int dp[4001][4001];
int main() {
	char str[4002], str2[4002];
	scanf("%s %s", str + 1, str2 + 1);

	int solve = 0;
	for(int i = 1; i < str[i]; i++) {
		for(int j = 1; j < str[j]; j++) {
			if(str[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			if(dp[i][j] > solve) solve = dp[i][j];
		}
	}

	return 0;
}