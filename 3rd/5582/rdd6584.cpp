#include <cstdio>
#include <cstring>

char sa[4001], sb[4001];
char visit[4000][4000] = { 0 };
int max = 0;

/* i, j���� �����ϴ� ���� ���ڿ��� ���̸� f(i, j)��� ���� ��, f(i, j) == k���, f(i+1 ~ i+k-1, j+1 ~ j+k-1)�� �׻� f(i, j)���� �۴ٴ� ������ ������ ���̵��. */
int main() {
	scanf("%s %s", sa, sb);

	int al = strlen(sa);
	int bl = strlen(sb);
	int c;

	for (int i = 0; i < al; i++)
		for (int j = 0; j < bl; j++) {
			c = 0;
			while (i + c < al && j + c < bl && !visit[i + c][j + c] && sa[i + c] == sb[j + c]) {
				visit[i + c][j + c] = 1;
				c++;
			}
			if (max < c) max = c;
		}

	printf("%d", max);
}