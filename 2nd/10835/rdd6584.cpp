#include <cstdio>
#include <memory.h>

using namespace std;

int dp[2000][2000];
int left[2000], right[2000];
int n;

/* left와 right를 각각 몇장 들어냈는지에 따라서 작은 문제로 정의한다. */

int go(int a, int b) {
	if (a == n || b == n) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	
	int c1, c2, c3 = 0;
	c1 = go(a + 1, b + 1);
	c2 = go(a + 1, b);
	if(left[a] > right[b]) c3 = go(a, b + 1) + right[b];

	return dp[a][b] = c1 > c2 ? (c1 > c3 ? c1 : c3) : (c2 > c3 ? c2 : c3);
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
		scanf("%d", &left[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &right[i]);

	printf("%d", go(0, 0));
}