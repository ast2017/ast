#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

int map[100][100];
int dst[100][100];
int cmp[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct vertex { int a, b; };
bool safe(int x, int y, int m_size) { return (x >= 0 && y >= 0) && (x < m_size && y < m_size); }

void make_map(int a, int b, int cnt, int m_size) {
	std::queue <vertex> q;
	vertex temp; temp.a = a; temp.b = b;
	q.push(temp);

	while(!q.empty()) {
		vertex cur = q.front();
		dst[cur.a][cur.b] = cnt;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int x = cur.a + dx[i];
			int y = cur.b + dy[i];
			if(safe(x, y, m_size) && map[x][y] == 1 && dst[x][y] == 0) {
				dst[x][y] = cnt;
				temp.a = x; temp.b = y;
				q.push(temp);
			}
		}
	}
}

int solve(int cnt, int m_size) {
	int ans = -1;
	std::queue <vertex> q;
	vertex temp;
	for(int c = 1; c <= cnt; c++) {
		for(int i = 0; i < m_size; i++) {
			for(int j = 0; j < m_size; j++) {
				cmp[i][j] = -1;
				if(dst[i][j] == c) {
					temp.a = i; temp.b = j;
					q.push(temp);
					cmp[i][j] = 0;
				}
			}
		}

		while(!q.empty()) {
			vertex cur = q.front(); q.pop();
			for(int i = 0; i < 4; i++) {
				int x = cur.a + dx[i];
				int y = cur.b + dy[i];
				if(safe(x, y, m_size) && cmp[x][y] == -1) {
					cmp[x][y] = cmp[cur.a][cur.b] + 1;
					temp.a = x; temp.b = y;
					q.push(temp);
				}
			}
		}
		for(int i = 0; i < m_size; i++) {
			for(int j = 0; j < m_size; j++) {
				if(map[i][j] == 1 && dst[i][j] != c)
					if(ans == -1 || cmp[i][j] - 1 < ans)
						ans = cmp[i][j] - 1;
			}
		}
	}

	return ans;
}

int input() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	return n;
}



int main() {
	int n = input();
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(dst[i][j] == 0 && map[i][j] == 1) {
				++cnt;
				make_map(i, j, cnt, n);
			}
		}
	}

	int ans = solve(cnt, n);
	printf("%d\n", ans);
	return 0;
}