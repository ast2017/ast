#include <cstdio>
#include <vector>
#define sz(x) (int)(x).size()
using namespace std;

vector<int> v[1000001];

char visit[1000001];
int dp[1000001][2];

int go(int o, int color) {
	visit[o] = 1;
	if (dp[o][color]) return dp[o][color];
	int sum = 0, a, b;

	if (!color) {
		for (int i = 0; i < sz(v[o]); i++)
			if (!visit[v[o][i]]) sum += go(v[o][i], 1);
	}
    
	else
		for (int i = 0; i < sz(v[o]); i++)
			if (!visit[v[o][i]]) sum += min(go(v[o][i], 1), go(v[o][i], 0));

	visit[o] = 0;
	return dp[o][color] = sum + color;
}

int main() {
	int n, a, b;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
    
	printf("%d", min(go(1, 0), go(1, 1)));
}