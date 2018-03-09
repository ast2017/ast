#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define mx 100000
struct par { int a, b; };
bool v[mx + 1];
int v2[mx + 1];

bool safe(int x) { return (x >= 0 && x < mx + 1); }

int bfs(int n, int k) {
	int ret = mx + 1;

	par temp; temp.a = n; temp.b = 0;

	std::queue<par> q;
	q.push(temp);

	while(!q.empty()) {
		par cur = q.front(); q.pop();
		int next = cur.a;
		int cnt = cur.b;

		v[next] = true;

		if(next == k) {
			v2[cnt] += 1;
			ret = ret > cnt ? cnt : ret;
		}

		if(safe(next - 1) && !v[next - 1]) {
			temp.a = next - 1;
			temp.b = cnt + 1;
			q.push(temp);
		}
		if(safe(next + 1) && !v[next + 1]) {
			temp.a = next + 1;
			temp.b = cnt + 1;
			q.push(temp);
		}
		if(safe(next * 2) && !v[next * 2]) {
			temp.a = next * 2;
			temp.b = cnt + 1;
			q.push(temp);
		}
	}

	return ret;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if(n == k) {
		printf("%d\n%d", 0, 1);
	} else {
		int ans = bfs(n, k);
		printf("%d\n%d", ans, v2[ans]);
	}

	return 0;
}