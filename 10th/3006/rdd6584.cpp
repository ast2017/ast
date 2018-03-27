#include <cstdio>
#include <algorithm>
using namespace std;
int tree[262144];
int szz;

void init(int i) {
	if (i >= szz) return;
	init(i * 2), init(i * 2 + 1);
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int i, int val) {
	i += szz -1;
	tree[i] = val;
	i /= 2;

	while (i) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
		i /= 2;
	}
}

int find(int i, int l, int r, int ll, int rr) {
	if (l > rr || r < ll || l > r) return 0;
	if (ll >= l && rr <= r) return tree[i];
	return find(i * 2, l, r, ll, (ll + rr) / 2) + find(i * 2 + 1, l, r, (ll + rr) / 2 + 1, rr);
}


int loca[100001]; // i�� ��ġ�� ��� �迭
/*
������ �� ���, �ڽź��� ���ʿ� �ִ� ������ ����, ���� ����.
�̹� ����� ���� �� ��ġ�� �׻� �����ǹǷ�, �������� �ϳ� �ٿ���.
*/

int main() {
	int n, temp;
	
	scanf("%d", &n);
	szz = 1;
	while (szz < n) szz *= 2;

	fill(tree + szz, tree + szz + n, 1);
	init(1);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		loca[temp] = i;
	}

	for (int i = 1; i <= n / 2; i++) {
		printf("%d\n", find(1, 1, loca[i] - 1, 1, szz));
		update(loca[i], 0);
		printf("%d\n", find(1, loca[n - i + 1] + 1, n, 1, szz));
		update(loca[n - i + 1], 0);
	}
	if (n % 2) printf("0\n");
}