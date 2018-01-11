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
	} // Ai = Ai-1의 배수이므로 그리드하게 가장 큰 동전부터 차례대로 구한다

	printf("%d", count);
}