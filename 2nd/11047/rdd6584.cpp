#include <cstdio>

int vec[10];

int main() {
	int n, k;
	int count = 0;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	
	for (int i = n - 1; i >= 0; i--) {
		count += k / vec[i];
		k %= vec[i];
	} // Ai = Ai-1�� ����̹Ƿ� �׸����ϰ� ���� ū �������� ���ʴ�� ���Ѵ�

	printf("%d", count);
}