#include<stdio.h>
#include<memory.h>

int mat[12][12];
int sum[12][12] = { 0 };
int tttt[12][12] = { 0 };
int n;
// 1~n�� �ε��� ���.

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
	// ���� �湮�� ��ǥ�� ���������� ���� �ǿ��� ���ϰ���.



	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++) {
			if (sum[i][j] < 9999) {
				memcpy(temp, sum, sizeof(temp));
				tt = go(o + 1, i, j);
				memcpy(sum, temp, sizeof(temp));
				if (ttt > tt) ttt = tt;
				// ��Ʈ��ŷ������ ���� �ܰ��� �迭 ���¸� �����Ͽ�, ���� Ž���ÿ� ��Ȱ��.
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
	// �̸� �ش������� ���� �ǿ� ����� ����� �����ش�.


	for (int i = 2; i < n; i++)
		for (int j = 2; j < n; j++) {
			memcpy(tttt, sum, sizeof(tttt));
			tt = go(1, i, j);
			memcpy(sum, tttt, sizeof(tttt));
			if (ttt > tt) ttt = tt;
		}

	printf("%d", ttt);
}