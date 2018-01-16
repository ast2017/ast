#include <cstdio>
#include <cstring>

char sa[4001], sb[4001];
char visit[4000][4000] = { 0 };
int max = 0;

/* i, j부터 시작하는 공통 문자열의 길이를 f(i, j)라고 뒀을 때, f(i, j) == k라면, f(i+1 ~ i+k-1, j+1 ~ j+k-1)은 항상 f(i, j)보다 작다는 점에서 착안한 아이디어. */
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