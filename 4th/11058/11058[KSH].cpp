#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
typedef long long ll;
ll d[101];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 7; i++) d[i] = i;
	for(int i = 7; i <= n; i++) {
		for(int j = 3; j < 6; j++) {
			ll cur = d[i - j] * (j - 1);
			if(cur > d[i]) d[i] = cur;
		}
	}
	printf("%lld\n", d[n]);
	return 0;
}