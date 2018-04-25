#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
const ll MOD = 1e9 + 7;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v; queue<int> q; deque<int> dq;

int dp[5000][5001];
int n;

int go(int o, int st) {
	if (o == n) {
		if(st == 0) return 1;
		else return 0;
	}
	if (dp[o][st] != -1) return dp[o][st];

	int sum = 0;
	if (st > 0) sum = go(o + 1, st - 1);
	sum = (sum + go(o + 1, st + 1)) % MOD;

	return dp[o][st] = sum;
}

int main() {
	int t;
	scanf("%d", &t);
	n = 5000;
	memset(dp, -1, sizeof(dp));
	go(0, 0);


	while (t--) {
		scanf("%d", &n);
		if (n % 2) printf("0\n");
		else printf("%d\n", dp[5000 - n][0]);
	}
}