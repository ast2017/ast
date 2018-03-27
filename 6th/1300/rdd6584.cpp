/*
이분탐색을 이용한 풀이
x보다 작은 값의 갯수 f(x) = x/ R(1~N) 들의 합
*/
#include<stdio.h>

int main() {
	int n, k, l, r, mid, temp;
	int sum;
	scanf("%d %d", &n, &k);

	l = 1;
	r = 1000000000;

	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			temp = mid / i;
			if (temp > n) temp = n;
			sum += temp;
		}
		
		if (sum < k) l = mid + 1;
		else r = mid - 1;
	}

	if (sum < k) printf("%d", mid + 1);
	else printf("%d", mid);
}