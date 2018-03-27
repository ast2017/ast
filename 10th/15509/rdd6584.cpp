#include <cstdio>
#include <vector>
#include <algorithm>
#define sz(x) (int)x.size()
using namespace std;

char mat[1001][1001] = { 0 };
int visit[1001] = { 0 };
char dp[501];
int n, k;
vector<int> v;

int go(int x) {
	visit[x] = 1;
	int sum = 0;

	for (int i = 1; i <= n; i++)
		if (mat[x][i] && !visit[i]) sum += go(i);

	return sum + 1;
}

/*
항상 같이 다녀야 하는 것들을 한 그룹으로 묶어서 생각하며,
DFS를 통해서 그룹들의 원소 갯수를 구한다.
그러면 문제는 그 원소 갯수들의 합으로 K를 만들 수 있는지 묻는 문제로 바뀜.
전형적인 Subset sum 문제
*/

int main() {
	int m, a, b;
	scanf("%d %d %d", &n, &m, &k);
	k = k < n - k ? k : n - k;

	while (m--) {
		scanf("%d %d", &a, &b);
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (!visit[i]) v.push_back(go(i));

	dp[0] = 1;
	for (int i = 0; i < sz(v); i++)
		for (int j = 500; j - v[i] >= 0; j--) {
			dp[j] |= dp[j - v[i]];
		}

	if (dp[k]) printf("SAFE");
	else printf("DOOMED");
}