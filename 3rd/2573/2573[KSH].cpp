#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

struct Vertex { int a, b; };
std::queue<Vertex> q;
int map[300][300];
int ds[300][300];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool safe(int x, int y) { return (x >= 0 && y >= 0) && (x < n && y < m); }

void input() {
	Vertex temp;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0) {
				ds[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] != 0) {
				for(int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if(safe(x, y) && map[x][y] == 0) {
						temp.a = i; temp.b = j;
						q.push(temp);
						break;
					}
				}
			}
		}
	}
}

void flood(int a, int b, int cnt) {
	std::queue<Vertex> q2;
	Vertex temp; temp.a = a; temp.b = b;
	ds[a][b] = cnt;
	q2.push(temp);

	while(!q2.empty()) {
		Vertex cur = q2.front(); q2.pop();
		for(int i = 0; i < 4; i ++) {
			int x = cur.a + dx[i];
			int y = cur.b + dy[i];
			if(safe(x, y) && ds[x][y] == 0 && map[x][y] != 0) {
				ds[x][y] = cnt;
				temp.a = x; temp.b = y;
				q2.push(temp);
			}
		}
	}
}

int remake_map() {
	int cnt = 0;
	Vertex temp;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ds[i][j] = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] != 0) {
				for(int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if(safe(x, y) && map[x][y] == 0) {
						temp.a = i; temp.b = j;
						q.push(temp);
						break;
					}
				}
			}
			if(map[i][j] != 0 && ds[i][j] == 0) {
				cnt++;
				if(cnt > 1) return cnt;
				flood(i, j, cnt);
			}
		}
	}
	return cnt;
}

int sol() {
	int k;
	for(k = 1; ; k++) {
		while(!q.empty()) {
			Vertex cur = q.front(); q.pop();
			for(int i = 0; i < 4; i++) {
				int x = cur.a + dx[i];
				int y = cur.b + dy[i];
				if(safe(x, y) && ds[x][y] == 0 && map[cur.a][cur.b] != 0) {
					map[cur.a][cur.b]--;
				}
			}
		}

		int cnt = remake_map();
		if(cnt > 1) return k;
		else if(cnt == 0) return 0;
	}
	return k;
}

int main() {
	input();
	int n = sol();
	printf("%d\n", n == 1 ? 0 : n);
	return 0;
}