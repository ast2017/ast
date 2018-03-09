#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

int m[2][100001];
int v[2][100001];
int dy[] = {1,-1};

struct ver { int a, b, cnt; };
bool safeY(int y, int cnt) { return y > cnt; }

bool bfs(int n, int k) {
	bool ret = false;
	std::queue<ver> q;
	ver temp; temp.a = 0; temp.b = 1; temp.cnt = 0;
	v[0][1] = 1;
	q.push(temp);

	while(!q.empty()) {
		ver cur = q.front(); q.pop();
		for(int i = 0; i < 2; i++) {
			int x = cur.a;
			int y = cur.b + dy[i];
			int cnt = cur.cnt + 1;
			if(safeY(y, cnt) && m[x][y] && !v[x][y]) {
				temp.a = x; temp.b = y; temp.cnt = cnt;
				v[x][y] = 1;
				q.push(temp);
			}
		}
		
		int x = cur.a == 0 ? cur.a + 1 : cur.a - 1;
		int y = cur.b + k;
		int cnt = cur.cnt + 1;
		if(m[x][y] && !v[x][y]) {
			temp.a = x; temp.b = y; temp.cnt = cnt;
			v[x][y] = 1;
			q.push(temp);
		}
		if(y > n) {
			ret = true;
			return ret;
		}
	}
	return ret;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < 2; i++)
		for(int j = 1; j <= n; j++)
			scanf("%1d", &m[i][j]);

	int ans = bfs(n, k);
	printf("%d\n", ans);

	return 0;
}