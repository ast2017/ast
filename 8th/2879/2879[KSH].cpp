#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int b[1002];
int a[1002];
int t[1002]; 
int main() {
	int n; scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", b + i);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		t[i] = b[i] - a[i];
	}

	int ans = 0;
	int temp = t[1];
	int cur = t[1];
	if(n == 1) {
		printf("%d\n", abs(cur));
		return 0;
	}

	for(int i = 2; i <= n; i++) {
		if(t[i] >= 0) {
			if(temp < 0) {
				ans += abs(temp);
				temp = t[i];
			} else {
				if(temp < t[i]) {
					temp = t[i];
				} else {
					cur = t[i];
					ans += abs(temp) - abs(cur);
					temp = cur;
				}
			}
		} else if(t[i] < 0) {
			if(temp > 0) {
				ans += temp;
				temp = t[i];
			} else {
				if(temp > t[i]) {
					temp = t[i];
				} else {
					cur = t[i];
					ans += abs(temp) - abs(cur);
					temp = cur;
				}
			}
		}
	}
	ans += abs(temp);
	printf("%d\n", ans);
	return 0;
}