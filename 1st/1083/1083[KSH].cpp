#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int arr[50];
int main() {
	int n, sort_cnt;
	int max_idx, max_num;

	while(scanf("%d", &n) != EOF) {

		for(int i = 0; i < n; i++) scanf("%d", arr + i);
		scanf("%d", &sort_cnt);

		for(int i = 0; i < n; i++) {
			max_idx = max_num = 0;

			int cmp_idx = 0;
			for(int j = i; j < n && cmp_idx <= sort_cnt; j++, cmp_idx++) {
				if(max_num < arr[j]) {
					max_num = arr[j];
					max_idx = j;
				}
			}


			for(int j = max_idx; j > i && sort_cnt >= 0; j--, sort_cnt--) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}

		}
		for(int i = 0; i < n; i++) printf("%d ", arr[i]);
		puts("");
	}
	return 0;
}
