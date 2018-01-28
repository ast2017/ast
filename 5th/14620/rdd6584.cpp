#include<stdio.h>
#include<memory.h>

int mat[12][12];
int sum[12][12] = { 0 };
int tttt[12][12] = { 0 };
int n;
// 1~n의 인덱스 사용.

int go(int o, int x, int y) {
	if (o == 3) return sum[x][y];
	int ss = sum[x][y];
	int tt;
	int ttt = 9999;
	int temp[12][12] = { 0 };


	for (int i = x - 2; i <= x + 2; i++)
		for (int j = y - 2; j <= y + 2; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) < 5)
				sum[i][j] = 9999;
	// 현재 방문한 좌표의 인접지점에 꽃을 피우지 못하게함.



	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++) {
			if (sum[i][j] < 9999) {
				memcpy(temp, sum, sizeof(temp));
				tt = go(o + 1, i, j);
				memcpy(sum, temp, sizeof(temp));
				if (ttt > tt) ttt = tt;
				// 백트래킹에서의 현재 단계의 배열 상태를 저장하여, 다음 탐색시에 재활용.
			}
		}



	return ss + ttt;
}

int main() {
	scanf("%d", &n);
	int tt, ttt = 9999;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &mat[i][j]);

	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++)
			sum[i][j] = mat[i][j] + mat[i + 1][j] + mat[i - 1][j] + mat[i][j + 1] + mat[i][j - 1];
	// 미리 해당지점에 꽃을 피울 경우의 비용을 구해준다.


	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++) {
			memcpy(tttt, sum, sizeof(tttt));
			tt = go(1, i, j);
			memcpy(sum, tttt, sizeof(tttt));
			if (ttt > tt) ttt = tt;
		}

	printf("%d", ttt);
}