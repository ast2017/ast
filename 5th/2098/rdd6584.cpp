#include <cstdio>
#include <memory.h>
#define INF 99999999

int n;
int mat[16][16] = { 0 };
int dp[15][1 << 15] = { 0 };
// dp[현재 위치][모든 도시 방문상태] = 최적 시간.
// 도시의 모든 방문상태를 Bitmask로 표현할 수 있다. 예를 들어 1101은 3 2 0번 도시를 방문한 상태라는 것.

int main() {
	scanf("%d", &n);
	int min = 2100000000, temp, mt;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &mat[i][j]);
			if(!mat[i][j]) mat[i][j] = INF;
		}
	
	// 그래프는 결국 시작지점으로 돌아오기 때문에 사이클을 형성한다.
	// (0 -> 2 -> 1 -> 0) == (2 -> 1 -> 0 -> 2)임은 자명하므로, 시작도시는 어느도시던지 상관이 없다.
	// 임의의 시작 도시의 번호를 i로 정해보자.
	// 그러면 i -> 임의의 도시들 -> i로 문제를 축소시킬 수 있다.
	// 아래 코드는 i를 n-1로 정함.
	n--;
	for (int i = 0; i < n; i++)
		dp[i][1 << i] = mat[n][i];
		
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				for (int j = 0; j < n; j++) {
					if (mask & (1 << j)) continue;
					mt = mask | (1 << j);
					temp = dp[i][mask] + mat[i][j];
					dp[j][mt] = (temp < dp[j][mt]) || !dp[j][mt] ? temp : dp[j][mt];
				}
		}
	}

	for (int i = 0; i < n; i++) {
		temp = dp[i][(1 << n) - 1] + mat[i][n];
		min = min < temp ? min : temp;
	}

	printf("%d", min);
}