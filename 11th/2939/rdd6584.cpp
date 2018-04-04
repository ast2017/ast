#include <cstdio>
#include <queue>
#define xx second.first
#define yy second.second
using namespace std;

typedef long long ll;

int dp[2001][2][2001][2];
int xsum[2001][2];
int ysum[2001][201];

int main() {
	int n, m, q, mv, dis;
	ll ans = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &xsum[i][0]);
		ysum[i][1] = xsum[i][0];
		for (int j = 2; j <= m - 1; j++) {
			scanf("%d", &ysum[i][j]);
			ysum[i][j] += ysum[i][j - 1];
		}

		if (m != 1) {
			scanf("%d", &xsum[i][1]);
			ysum[i][m] = xsum[i][1] + ysum[i][m - 1];
		}
		else
			xsum[i][1] = xsum[i][0];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][0][i][0] = xsum[i][0];
		dp[i][1][i][1] = xsum[i][1];

		mv = ysum[i][m];
		dis = 0;

		for (int j = i + 1; j <= n; j++) {
			dis += xsum[j - 1][0] + xsum[j - 1][1];
			mv = min(mv, dis + ysum[j][m]);
		}

		dis = 0;
		for (int j = i - 1; j >= 1; j--) {
			dis += xsum[j + 1][0] + xsum[j + 1][1];
			mv = min(mv, dis + ysum[j][m]);
		}

		dp[i][0][i][1] = dp[i][1][i][0] = mv;
	}

	for (int ux = 1; ux <= n; ux++)
		for (int uy = 0; uy < 2; uy++)
			for (int vx = ux + 1; vx <= n; vx++)
				for (int vy = 0; vy < 2; vy++)
					dp[ux][uy][vx][vy] = dp[vx][vy][ux][uy] = min(
						dp[ux][uy][vx - 1][0] + dp[vx][0][vx][vy],
						dp[ux][uy][vx - 1][1] + dp[vx][1][vx][vy]
					);

	scanf("%d", &q);
	int sx = 1, sy = 1, ex, ey;
	ans += xsum[1][0];

	while (q--) {
		mv = 2e9;
		scanf("%d %d", &ex, &ey);

		if (sx == ex) {
			if (sy > ey) {
				mv = min(mv, ysum[sx][sy] - ysum[ex][ey - 1]);
				mv = min(mv, ysum[ex][ey] - ysum[ex][1] + dp[ex][0][sx][1] + ysum[sx][m - 1] - ysum[sx][sy - 1]);
			}
			else {
				mv = min(mv, ysum[ex][ey] - ysum[sx][sy - 1]);
				mv = min(mv, ysum[sx][sy] - ysum[sx][1] + dp[sx][0][ex][1] + ysum[ex][m - 1] - ysum[ex][ey - 1]);
			}
		}
		else {
			mv = min(mv, ysum[sx][sy] - ysum[sx][1] + dp[sx][0][ex][0] + ysum[ex][ey] - ysum[ex][1]);
			mv = min(mv, ysum[sx][sy] - ysum[sx][1] + dp[sx][0][ex][1] + ysum[ex][m - 1] - ysum[ex][ey - 1]);
			mv = min(mv, ysum[sx][m - 1] - ysum[sx][sy - 1] + dp[sx][1][ex][0] + ysum[ex][ey] - ysum[ex][1]);
			mv = min(mv, ysum[sx][m - 1] - ysum[sx][sy - 1] + dp[sx][1][ex][1] + ysum[ex][m - 1] - ysum[ex][ey - 1]);
		}
		ans += mv - (ysum[sx][sy] - ysum[sx][sy - 1]);
		sx = ex, sy = ey;
	}

	printf("%lld", ans);
}