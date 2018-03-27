/* 재귀DP를 이용한 풀이
숫자맞추기와 동일하게 위부터 맞춰나가는 것이 항상 최적
그러면 DP[순서][현재 돌아간 양][다음 돌아간 양] = 최솟값을 저장하여 해결.

*/
#include <cstdio>
#include <memory.h>

int vec[100], ob[100];
int dp[100][10][10];

int n;
int go(int o, int now, int next) {
	if (o == n) return 0;
	if(now < 0) now += 10; if(next < 0) next += 10;
	now %= 10; next %= 10;
	if (dp[o][now][next] != -1) return dp[o][now][next];

	int min = 9999; int tt = (vec[o] + now) % 10;
	int t1, t2, temp, k;

	t1 = t2 = ob[o] - tt;
	if(t1 < 0) t1 += 10;
	else t2 -= 10;
	
	// i + j + k <= t1인 모든 i,j,k쌍에 대해서 탐색.
	for(int i = 0; i <= t1; i++)
		for(int j = 0; i + j <= t1; j++){
				k = t1 - (i + j);
				temp = go(o + 1, next + j + k, k);
				temp += (i + 2) / 3 + (j + 2) / 3 + (k + 2) / 3;
				if(temp < min) min = temp;
			}
			
	for(int i = 0; i >= t2; i--)
		for(int j = 0; i + j >= t2; j--) {
				k = t2 - (i + j);
				temp = go(o + 1, next + j + k, k);
				temp -= (i - 2) / 3 + (j - 2) / 3 + (k - 2) / 3;
				if(temp < min) min = temp;
			}

	return dp[o][now][next] = min;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%1d", &vec[i]);
		
	for (int i = 0; i < n; i++)
		scanf("%1d", &ob[i]);

	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, 0, 0));
}