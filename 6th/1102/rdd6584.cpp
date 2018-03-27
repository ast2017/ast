// 방문상태를 bitset을 이용하여 저장.
// 방문상태에 따른 값 메모이제이션.
#include <cstdio>

struct data {
	int c;
	int cost;
	data() {
		c = -1;
		cost = -1;
	}
};

int mat[16][16];
char temp;
int cnt = 0, oc;
int stat = 0;
data dp[1 << 16];

int main() {
	int n, tp, min = 999999;
	scanf("%d", &n);
	int maxn = 1 << n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &temp);
		if (temp == 'Y') {
			stat |= 1 << i;
			cnt++;
		}
	}
	scanf("%d", &oc);
	dp[stat].c = cnt;
	dp[stat].cost = 0;

	for (int mask = stat; mask < maxn; mask++) {
		if (dp[mask].c >= oc) {
			if (min > dp[mask].cost) min = dp[mask].cost;
			continue;
		}

		if (dp[mask].c != -1)
			for (int i = 0; i < n; i++) {
				
				if (mask & (1 << i))
					for (int j = 0; j < n; j++) {
						tp = mask | (1 << j);
						if (dp[tp].c == -1 || dp[tp].cost > dp[mask].cost + mat[i][j]) {
							dp[tp].cost = dp[mask].cost + mat[i][j];
							dp[tp].c = dp[mask].c + 1;
						}
					}
			}
	}
	if (min == 999999) printf("-1");
	else printf("%d", min);
}