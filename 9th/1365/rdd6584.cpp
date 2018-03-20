#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;
int tree[262144];
pii vec[100000];
int szz = 1;

void init(int i) {
	if (i >= szz) return;
	init(i * 2), init(i * 2 + 1);
	tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

void update(int i, int val) {
	i += szz;
	tree[i] = val;
	i /= 2;

	while (i) {
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
		i /= 2;
	}
}

int find(int i, int l, int r, int ll, int rr) {
	if (l > rr || r < ll) return 0;
	if (ll >= l && rr <= r) return tree[i];
	return max(find(i * 2, l, r, ll, (ll + rr) / 2), find(i * 2 + 1, l, r, (ll + rr) / 2 + 1, rr));
}

int main() {
	int n, max = 0, temp;
	scanf("%d", &n);
	while (szz < n) szz *= 2;

	for (int i = 0; i < n; i++) {
		scanf("%d", &vec[i].first);
		vec[i].second = i;
	}
	sort(vec, vec + n);

	for (int i = 0; i < n; i++) {
		temp = find(1, 0, vec[i].second, 0, szz - 1) + 1;
		if (max < temp) max = temp;
		update(vec[i].second, temp);
	}

	printf("%d", n - max);
}