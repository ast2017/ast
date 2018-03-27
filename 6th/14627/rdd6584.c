/*
�̺�Ž���� �̿��� Ǯ��.
�ϳ��� �߿� �ִ��� �� �ĸ� �־����.
�� ���� ������ x�� �����鼭 Ȯ���Ѵ�.
*/
#include<stdio.h>

int vec[1000000];

int main() {
	int s, c, rotn;
	long long sum, max = 0;
	scanf("%d %d", &s, &c);

	for (int i = 0; i < s; i++) {
		scanf("%d", &vec[i]);
		if (max < vec[i]) max = vec[i];
	}

	long long l = 1, r = max, mid;
	max = 9999999999999999;

	while (l <= r) {
		sum = 0;
		rotn = 0;
		mid = (l + r) / 2;
		
		for (int i = 0; i < s; i++) {
			rotn += vec[i] / mid;
			sum += vec[i] % mid;
		}

		if (rotn < c) r = mid - 1;
		else {
			l = mid + 1;
			sum += (rotn - c) * mid;
			if (sum < max) max = sum;
		}
	}

	printf("%lld", max);
}