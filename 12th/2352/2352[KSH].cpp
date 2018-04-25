#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int dp[44444], a[44444];
int main() {
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", a + i);

	dp[0] = a[0];

	int idx = 0;
	for(int i = 1; i < N; i++) {
		if(dp[idx] > a[i]) {
			int cidx = idx;
			while(cidx - 1 >= 0 && dp[cidx - 1] > a[i]) {
				cidx--;
			}
			dp[cidx] = a[i];
		} else {
			idx++;
			dp[idx] = a[i];
		}
	
	}
	printf("%d\n", idx + 1);

	return 0;
}
