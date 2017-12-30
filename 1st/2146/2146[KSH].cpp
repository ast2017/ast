#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

int m[100][100];
int d[100][100];
int cmp[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct vertex { int a, b; };

bool safe(int a, int b, int n) {
	return (a >= 0 && b >= 0) && (a < n && b < n);
}

void f(int a, int b, int cnt, int n) {
	std::queue<vertex> q;
	d[a][b] = cnt;
	vertex temp; temp.a = a; temp.b = b;
	q.push(temp);
	while(!q.empty()) {
		vertex cur = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int x = cur.a + dx[i];
			int y = cur.b + dy[i];
			if(safe(x, y, n) && m[x][y] == 1 && d[x][y] == 0) {
				d[x][y] = cnt;
				temp.a = x; temp.b = y;
				q.push(temp);
			}
		}
	}
}

int search(int n) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(m[i][j] == 1 && d[i][j] == 0) {
				cnt++;
				f(i, j, cnt, n);
			}
		}
	}
	return cnt;
}

int input() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	return n;
}

int bf(int cnt, int n) {
	std::queue<vertex> q;
	vertex temp;
	int ans = -1;
	for(int k = 1; k <= cnt; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cmp[i][j] = -1;
				if(d[i][j] == k) {
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
				if(safe(x, y, n) && cmp[x][y] == -1) {
					cmp[x][y] = cmp[cur.a][cur.b] + 1;
					temp.a = x; temp.b = y;
					q.push(temp);
				}
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(m[i][j] == 1 && d[i][j] != k) {
					if(ans == -1 || cmp[i][j] - 1 < ans) {
						ans = cmp[i][j] - 1;
					}
				}
			}
		}
	}

	return ans;
}


int main() {
	int n = input();
	int cnt = search(n);
	printf("%d\n", bf(cnt, n));
	return 0;
}