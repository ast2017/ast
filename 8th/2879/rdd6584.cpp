#include <cstdio>

int vec[1001];

// ���� ���� ��ǥ�� ���� ���̸� vec�迭�� ����ش�.
// ������ ��������, ����� ������� ��� ����ϴ� ���� �׻� ����.
// ��� ����� �� ���ٸ�, 1���� �߰��� �Ҹ��ؾ� �ϹǷ�, count+
// ����ܰ� count�� 0�̸� vec�� ��� 0�̶�� ������ �� ����.
// �ð����⵵ O(n * 80)

int main() {
	int n, temp;
	int sum = 0, c = 1;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &vec[i]);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		vec[i] -= temp;
	}

	while (c) {
		c = 0;
		for (int i = n; i > 0; i--) {
			if (vec[i] > 0) {
				if (vec[i - 1] <= 0) c++;
				vec[i]--;
			}
			else if (vec[i] < 0) {
				if (vec[i - 1] >= 0) c++;
				vec[i]++;
			}
		}
		
		sum += c;
	}

	printf("%d", sum);
}