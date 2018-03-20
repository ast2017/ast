#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int road[101][2];
int bike[101][2];
int dp[101][100001];
int ans(int n, int k, int i, int time){
	if(i >= n) return 0;
	if(time > k) return -100001;
	if(dp[i][time] != -1)
		return dp[i][time];

	dp[i][time] = -100001;

	if(k - time >= road[i][0] && ans(n, k, i + 1, time + road[i][0]) != -100001){
		dp[i][time] = max(dp[i][time], ans(n, k, i + 1, time + road[i][0]) + road[i][1]);
	}
	if(k - time >= bike[i][0] && ans(n, k, i + 1, time + bike[i][0]) != -100001){
		dp[i][time] = max(dp[i][time], ans(n, k, i + 1, time + bike[i][0]) + bike[i][1]);
	}

	return dp[i][time];
}

int main(){
	int n, k; scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &road[i][0], &road[i][1], &bike[i][0], &bike[i][1]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", ans(n, k, 0, 0));
	return 0;
}