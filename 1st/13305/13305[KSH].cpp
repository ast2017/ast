#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

typedef long long ll;
int d[100001];
ll p;
ll min = 0x7FFFFFFF;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) scanf("%d", d + i);

	for(int i = 1; i < n; i++) {
		int a;
		scanf("%d", &a);
		if(min > a) min = a;
		p += min * d[i];
	}

	printf("%lld\n", p);
	return 0;
}