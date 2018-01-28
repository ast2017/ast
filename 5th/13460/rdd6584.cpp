// 정신건강을 위해 최적화따위는 안했습니다. ㅠㅠ
// 배열은 계산의 편의를 위해 1~n의 인덱스를 사용했습니다.
#include <cstdio>

char mat[12][12];

int go(int o, int rx, int ry, int bx, int by) {
	if (o == 11) return 9999;

	int rrx, rry, bbx, bby, min = 9999, temp, ttt;
	int live;

	if (rx > bx) {
		rrx = rx, bbx = bx;
		live = 1; ttt = 0;
		while (mat[rrx + 1][ry])
			if (mat[++rrx][ry] == 2) { ttt = o; rrx = 999; break; }

		while (mat[bbx + 1][by] && (bbx + 1 != rrx || ry != by))
			if (mat[++bbx][by] == 2) { live = 0; }


		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rrx, ry, bbx, by);
			if (min > temp) min = temp;
		}

		rrx = rx, bbx = bx;
		live = 1; ttt = 0;
		while (mat[bbx - 1][by])
			if (mat[--bbx][by] == 2) { live = 0; }

		while (mat[rrx - 1][ry] && (rrx - 1 != bbx || ry != by))
			if (mat[--rrx][ry] == 2) { ttt = o; rrx = 999; break; }

		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rrx, ry, bbx, by);
			if (min > temp) min = temp;
		}
	}

	else {
		rrx = rx, bbx = bx;
		live = 1; ttt = 0;
		while (mat[rrx - 1][ry])
			if (mat[--rrx][ry] == 2) { ttt = o; rrx = 999; break; }

		while (mat[bbx - 1][by] && (bbx - 1 != rrx || ry != by))
			if (mat[--bbx][by] == 2) { live = 0; }

		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rrx, ry, bbx, by);
			if (min > temp) min = temp;
		}

		rrx = rx, bbx = bx;
		live = 1; ttt = 0;
		while (mat[bbx + 1][by])
			if (mat[++bbx][by] == 2) { live = 0; }

		while (mat[rrx + 1][ry] && (rrx + 1 != bbx || ry != by))
			if (mat[++rrx][ry] == 2) { ttt = o; rrx = 999; break; }

		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rrx, ry, bbx, by);
			if (min > temp) min = temp;
		}
	}

	if (ry > by) {
		rry = ry, bby = by;
		live = 1; ttt = 0;
		while (mat[rx][rry + 1])
			if (mat[rx][++rry] == 2) { ttt = o; rry = 999; break; }

		while (mat[bx][bby + 1] && (bby + 1 != rry || rx != bx))
			if (mat[bx][++bby] == 2) { live = 0; }
		
		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rx, rry, bx, bby);
			if (min > temp) min = temp;
		}

		rry = ry, bby = by;
		live = 1; ttt = 0;
		while (mat[bx][bby - 1])
			if (mat[bx][--bby] == 2) { live = 0; }

		while (mat[rx][rry - 1] && (rry - 1 != bby || rx != bx))
			if (mat[rx][--rry] == 2) { ttt = o; rry = 999; break; }
		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rx, rry, bx, bby);
			if (min > temp) min = temp;
		}
	}

	else {
		rry = ry, bby = by;
		live = 1; ttt = 0;
		while (mat[rx][rry - 1]) {
			
			if (mat[rx][--rry] == 2) { ttt = o; rry = 999; break; }
		}
		while (mat[bx][bby - 1] && (bby - 1 != rry || rx != bx))
			if (mat[bx][--bby] == 2) { live = 0; }
		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rx, rry, bx, bby);
			if (min > temp) min = temp;
		}

		rry = ry, bby = by;
		live = 1; ttt = 0;
		while (mat[bx][bby + 1])
			if (mat[bx][++bby] == 2) { live = 0; }

		while (mat[rx][rry + 1] && (rry + 1 != bby || rx != bx))
			if (mat[rx][++rry] == 2) { ttt = o; rry = 999; break; }
		if (live) {
			if (ttt) return ttt;
			temp = go(o + 1, rx, rry, bx, bby);
			if (min > temp) min = temp;
		}
	}

	return min;
}

int main() {
	int n, m;
	int rx, ry, bx, by, temp;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &mat[i][j]);
			if (mat[i][j] == 'R') {
				rx = i, ry = j;
				mat[i][j] = '.';
			}
			else if (mat[i][j] == 'B') {
				bx = i, by = j;
				mat[i][j] = '.';
			}
			if (mat[i][j] == '#') mat[i][j] = 0;
			else if (mat[i][j] == '.') mat[i][j] = 1;
			else if (mat[i][j] == 'O') mat[i][j] = 2;
			
		}

	temp = go(1, rx, ry, bx, by);
	if (temp > 10) printf("-1");
	else printf("%d", temp);
}