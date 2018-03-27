/*
빈 공간을 모두 벡터에 집어넣고,
차례대로 꺼내면서 백트래킹
*/
#include <cstdio>
#include <vector>
using namespace std;

struct node{
	int x;
	int y;
};

int mat[9][9];
int ans = 0;
vector<node> v;

void go(int o) {
	if (o == (int)v.size()) ans = 1;
	if (ans) return;

	int vec[10] = { 0 };
	int xx = v[o].x, yy = v[o].y;

	for (int i = 0; i < 9; i++)
		vec[mat[i][yy]] = 1;

	for (int i = 0; i < 9; i++)
		vec[mat[xx][i]] = 1;

	for (int i = xx / 3 * 3; i < xx / 3 * 3 + 3; i++)
		for (int j = yy / 3 * 3; j < yy / 3 * 3 + 3; j++)
			vec[mat[i][j]] = 1;

	for (int i = 1; i < 10; i++) {
		if (!vec[i]) {
			mat[xx][yy] = i;
			go(o + 1);
			if (ans) return;
			mat[xx][yy] = 0;
		}
	}
}

int main() {
	node tv;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &mat[i][j]);
			if (!mat[i][j]) {
				tv.x = i, tv.y = j;
				v.push_back(tv);
			}
		}

	go(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}