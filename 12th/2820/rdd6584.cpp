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
vector<int> v[500000]; queue<int> q; deque<int> dq;

pii lr[500000];
pii te[500000];
int lz[1048576];
int szz = 1;
int num = 0;

void update(int i, int l, int r, int ll, int rr, int val) {
	if (l > rr || r < ll) return;
	if (ll >= l && rr <= r) {
		lz[i] += val;
		return;
	}

	update(i * 2, l, r, ll, (ll + rr) / 2, val);
	update(i * 2 + 1, l, r, (ll + rr) / 2 + 1, rr, val);
}

int find(int i, int l, int r, int ll, int rr, int lzz) {
	lzz += lz[i];
	if (l > rr || r < ll) return 0;
	if (ll >= l && rr <= r) return lzz;

	return find(i * 2, l, r, ll, (ll + rr) / 2, lzz) + find(i * 2 + 1, l, r, (ll + rr) / 2 + 1, rr, lzz);
}

void go(int o) {
	te[o].first = num++;
	lr[o].first = num;

	for (int i = 0; i < sz(v[o]); i++)
		go(v[o][i]);

	lr[o].second = num - 1;
}
// 자식이 없는 경우 고려.

int main() {
	int n, m, a, b;
	char c;
	scanf("%d %d", &n, &m);

	while (szz < n) szz *= 2;
	scanf("%d", &a);
	te[0].second = a;

	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[b - 1].push_back(i);
		te[i].second = a;
	}
	go(0);

	while (m--) {
		scanf(" %c", &c);
		if (c == 'p') {
			scanf("%d %d", &a, &b);
			a--;
			if (lr[a].first <= lr[a].second) update(1, lr[a].first, lr[a].second, 1, szz, b);
		}
		else {
			scanf("%d", &a);
			a--;
			printf("%d\n", te[a].second + find(1, te[a].first, te[a].first, 1, szz, 0));
		}
	}
}