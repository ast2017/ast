#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int d[100001];
int main() {
	int n; scanf("%d", &n);
	d[0] = 1; d[1] = 3;

	for(int i = 2; i <= n; i++) {
		d[i] = (d[i - 1] * 2 + d[i - 2]) % 9901;
	}

	for(int i = 0; i <= n; i++) {
		printf("d[%d]: %d\n", i, d[i]);
	}
	return 0;
}