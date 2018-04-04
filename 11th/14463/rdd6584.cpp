#include <cstdio>

int vec[50001];
int tree[50001];
int n;

void update(int i, int val) {
	while (i <= n) {
		tree[i] += val;
		i += (i & -i);
	}
}

int find(int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}

	return sum;
}

int main() {
	int temp, cnt = 1;
	long long sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &temp);
		if (!vec[temp]) {
			vec[temp] = cnt;
			update(cnt++, 1);
		}
		else {
			sum += find(cnt) - find(vec[temp]);
			update(vec[temp], -1);
		}
	}

	printf("%lld", sum);
}