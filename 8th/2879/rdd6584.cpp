#include <cstdio>

int vec[1001];

// 현재 값과 목표한 값의 차이를 vec배열에 담아준다.
// 음수는 음수끼리, 양수는 양수끼리 묶어서 계산하는 것이 항상 최적.
// 묶어서 계산할 수 없다면, 1번을 추가로 소모해야 하므로, count+
// 현재단계 count가 0이면 vec가 모두 0이라고 간주할 수 있음.
// 시간복잡도 O(n * 80)

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