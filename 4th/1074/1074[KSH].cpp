#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int n, r, c, sol;
void solve(int n, int x, int y) {
	if(x == r && y == c) {
		printf("%d\n", sol);
		return;
	}

	if((x <= r && r < x + n) && (y <= c && c < y + n)) {
		solve(n / 2, x, y);
		solve(n / 2, x, y + n / 2);
		solve(n / 2, x + n / 2, y);
		solve(n / 2, x + n / 2, y + n / 2);
	} else {
		sol += n * n;
		return ;
	}
}

int main() {
	scanf("%d %d %d", &n, &r, &c);
	solve(1 << n, 0, 0);
	return 0;
}