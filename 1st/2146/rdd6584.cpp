// 가장자리를 모두 큐에 집어넣어서 모든 섬으로 부터 하나씩 BFS해봄.
// 확장판 문명문제.
#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

struct node {
	int x, y;
	int val;
};

char mat[100][100] = { 0 };
char visit[100][100];
char isl[100][100] = { 0 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n;

queue<node> q;
node t;

void chk(int x, int y) {	// 현재 방문한 섬을 모두 체크.
	isl[x][y] = visit[x][y] = 1;
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i]; yy = y + dy[i];
		if (xx >= n || yy >= n || xx < 0 || yy < 0) continue;
		if (!mat[xx][yy]) {
			t.x = x;
			t.y = y;
			q.push(t);	// 가장자리는 q에 push
		}
		if (!visit[xx][yy] && mat[xx][yy]) chk(xx, yy);
	}
}

int bfs() {
	node v, tv;
	int xx, yy;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			xx = v.x + dx[i]; yy = v.y + dy[i];
			if (xx >= n || yy >= n || xx < 0 || yy < 0) continue;
			if (!visit[xx][yy]) {
				if(mat[xx][yy]) return v.val;	// 시작섬은 이미 visit처리가 되어 있으므로 visit하지 않은 섬은 다른 섬.
				else {
					visit[xx][yy] = 1;
					tv.x = xx; tv.y = yy;
					tv.val = v.val + 1;
					q.push(tv);
				}
			}
		}
	}
}

int go(int x, int y) {
	memset(visit, 0, sizeof(visit));
	while (!q.empty()) q.pop();
	chk(x, y);

	return bfs();
}

int main() {
	int min = 99999, temp;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%hhd", &mat[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mat[i][j] && !isl[i][j]) temp = go(i, j);
			if (min > temp) min = temp;
		}

	printf("%d", min);
}