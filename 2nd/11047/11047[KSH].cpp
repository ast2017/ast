#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int d[11] = {0,};
	int n, m, a = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", d + i);
	for(int i = n - 1; i >= 0; i--) {
		a += m / d[i];
		m %= d[i];
	}
	printf("%d\n", a);

	return 0;
}