#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

pli tree[200002];
const int MOD = 1e9 + 7;

void add(int i, pli val) {
	while (i <= 200001) {
		tree[i].first += val.first;
		tree[i].second += val.second;
		i += i & -i;
	}
}

pli find(int i) {
	pli sum = { 0, 0 };
	while (i) {
		sum.first += tree[i].first;
		sum.second += tree[i].second;
		i -= i & -i;
	}

	return sum;
}

int main() {
	int n, temp;
	pli a, b;
	ll ans = 1, tt;
	scanf("%d", &n);
	scanf("%d", &temp);
	n--;
	add(temp + 1, { temp + 1, 1 });

	while (n--) {
		scanf("%d", &temp);
		temp++;
		a = find(200001), b = find(temp);
		tt = ((a.first - b.first) - (ll)temp * (a.second - b.second)) % MOD;
		tt = (tt + (b.second * (ll)temp - b.first)) % MOD;
		ans = ans * tt % MOD;

		add(temp, { temp, 1 });
	}

	printf("%lld", ans);
}