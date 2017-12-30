// 재귀 DP
#include <cstdio>
#include <memory.h>

int dp[10000][10];
int vec[10000];
int ob[10000];

int n;

int go(int x, int p){
	if(x >= n) return 0;
	if(dp[x][p] != -1) return dp[x][p];

	int temp = (vec[x] + p) % 10;
	int c1 = ob[x] - temp, c2 = temp - ob[x];
	if(c1 < 0) c1 += 10; if(c2 < 0) c2 += 10;

	c1 += go(x+1, (c1 + p) % 10);
	c2 += go(x+1, p);
	
	return dp[x][p] =  c1 < c2 ? c1 : c2;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%1d", &vec[i]);
	for(int i = 0; i < n; i++) scanf("%1d", &ob[i]);
	
	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, 0));

}


// 반복 DP
#include <cstdio>
#include <memory.h>
#define MIN(a, b) (a) < (b) ? (a) : (b)

int dp[10001][10] = {0};
int vec[10000];
int ob[10000];

int main() {
	int n, t1, t2, t3;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%1d", &vec[i]);
	for (int i = 0; i < n; i++) scanf("%1d", &ob[i]);

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < 10; j++) {
			t1 = (vec[i] + j) % 10;
			t2 = t1 - ob[i];
			t3 = ob[i] - t1;
			if (t2 < 0) t2 += 10;
			if (t3 < 0) t3 += 10;

			dp[i][j] = MIN(dp[i + 1][j] + t2, dp[i + 1][(j + t3) % 10] + t3);
		}

	printf("%d", dp[0][0]);
}
