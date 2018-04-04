#include <cstdio>
#include <memory.h>

int tree[200001];
int loca[100001];
int n, m;

void add(int i, int val) {
	while (i <= n + m) {
		tree[i] += val;
		i += i & -i;
	}
}

int find(int i) {
	int sum = 0;
	while (i) {
		sum += tree[i];
		i -= i & -i;
	}

	return sum;
}

int main() {
	int t, a;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		memset(tree, 0, sizeof(tree));
		for (int i = n; i > 0; i--) {
			loca[i] = n - i + 1;
			add(i, 1);
		}

		for (int i = 1; i <= m; i++) {
			scanf("%d", &a);
			printf("%d ", n - find(loca[a]));
			add(loca[a], -1);
			loca[a] = n + i;
			add(loca[a], 1);
		}

		printf("\n");
	}
}