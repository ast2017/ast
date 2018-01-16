#include <cstdio>
#include <memory.h>

int n, m;
char mat[300][300];	// 빙산의 정보
char visit[300][300];	// 매 1년마다의 visit배열
int count[300][300];	// 매 1년마다 인접한 바다의 갯수를 카운트

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void go(int x, int y) {	// 인접한 땅이 빙산이면 방문하고, 바다면 count++를 증가.
	visit[x][y] = 1;
	int xx, yy;

	for (int i = 0; i < 4; i++) {
		xx = x + dx[i], yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy]) continue;
		if (mat[xx][yy]) go(xx, yy);
		else count[x][y]++;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int xx, yy, cnt, h = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%hhd", &mat[i][j]);

	while (1) {
		memset(visit, 0, sizeof(visit));
		memset(count, 0, sizeof(count));
		cnt = 0;
		for (int i = 0; i < n; i++) // cnt는 빙산이 몇 조각인지 체크.
			for (int j = 0; j < m; j++)
				if (mat[i][j] && !visit[i][j]) {
					go(i, j);
					cnt++;
				}

		if (cnt > 1) { printf("%d", h); return 0; } // 2조각 이상시
		if (!cnt) { printf("0"); return 0; } // 빙산 동시에 녹은 경우
		h++;


		for (int i = 0; i < n; i++) // go로 기록한 count에 따라 빙산의 높이 감소
			for (int j = 0; j < m; j++) {
				mat[i][j] -= count[i][j];
				if (mat[i][j] < 0) mat[i][j] = 0;
			}
	}
}