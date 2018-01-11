#include <cstdio>
#include <memory.h>
#define MOD 9901

using namespace std;

int n;
int dp[100000][3];

/*
이전 단계에서, 왼쪽이었는지, 오른쪽이었는지 없었는지에 따라서
또 하나의 작은 문제로 정의된다.
*/
int go(int o, int pre) {
	if (o == n) return 1;
	if (dp[o][pre] != -1) return dp[o][pre];

	int count = 0;
	if (pre != 1) count = (count + go(o + 1, 1)) % MOD;
	if (pre != 2) count = (count + go(o + 1, 2)) % MOD;
	count = (count + go(o + 1, 0)) % MOD;

	return dp[o][pre] = count;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, 0));
	scanf("%d");
}