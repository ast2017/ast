/*
이전에 나왔던 최댓값중, 다시 최댓값을 계산한다.
DP수식은, j단계에서 i단계로 갈 때 드래그 + 복사하고
나머지를 전부 붙여넣기 한 것을 표현함.
*/
#include <cstdio>
#include <memory.h>
#define MAX(a, b) (a) > (b) ? (a) : (b)
long long dp[101];

int main(){
	int n;
	scanf("%d", &n);
	
	dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4, dp[5] = 5;
	
	for(int i = 6; i <= n; i++)
		for(int j = 2; j <= i - 3; j++)
			dp[i] = MAX(dp[i], dp[j] * (i - j - 2) + dp[j]);
	
	printf("%lld", dp[n]);
}