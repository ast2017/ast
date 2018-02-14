#include<stdio.h>

int stack[6][300000];
int top[6] = { -1, -1, -1, -1, -1, -1 };
int n, p;
int t1, t2, sum = 0;

// 기타 줄 하나당 스택을 하나씩 만들면 쉽게 해결할 수 있다.

int main() {
	scanf("%d %d", &n, &p);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t1, &t2);

		while (top[t1 - 1] >= 0 && stack[t1 - 1][top[t1 - 1]] > t2) {
			top[t1 - 1]--; sum++;
		}

		if (top[t1 - 1] == -1 || stack[t1 - 1][top[t1 - 1]] != t2) {
			stack[t1 - 1][++top[t1 - 1]] = t2;
			sum++;
		}
	}
	printf("%d", sum);
}