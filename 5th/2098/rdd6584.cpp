#include <cstdio>
#include <memory.h>
#define INF 99999999

int n;
int mat[16][16] = { 0 };
int dp[15][1 << 15] = { 0 };
// dp[���� ��ġ][��� ���� �湮����] = ���� �ð�.
// ������ ��� �湮���¸� Bitmask�� ǥ���� �� �ִ�. ���� ��� 1101�� 3 2 0�� ���ø� �湮�� ���¶�� ��.

int main() {
	scanf("%d", &n);
	int min = 2100000000, temp, mt;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &mat[i][j]);
			if(!mat[i][j]) mat[i][j] = INF;
		}
	
	// �׷����� �ᱹ ������������ ���ƿ��� ������ ����Ŭ�� �����Ѵ�.
	// (0 -> 2 -> 1 -> 0) == (2 -> 1 -> 0 -> 2)���� �ڸ��ϹǷ�, ���۵��ô� ������ô��� ����� ����.
	// ������ ���� ������ ��ȣ�� i�� ���غ���.
	// �׷��� i -> ������ ���õ� -> i�� ������ ��ҽ�ų �� �ִ�.
	// �Ʒ� �ڵ�� i�� n-1�� ����.
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